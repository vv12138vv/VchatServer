//
// Created by vv12138vv on 10/15/2023.
//

#include "server.h"

#include <utility>

Server::Server(QObject *parent) : QTcpServer(parent) {
    logger = new Logger(this);
    qDebug()<<"main thread"<<QThread::currentThread()<<"start"<<"\n";
}


bool Server::listenTo(quint32 port) {
    if (!this->listen(QHostAddress::AnyIPv4, port)) {
        //Todo need error log
        return false;
    }
    logger->log(Logger::LogType::StartListen, QString("Tcp成功监听端口：%1").arg(port));
//    connect(this, &Server::newConnection, this, &Server::onNewConnection);
//    connect(udpSocket_,&QUdpSocket::readyRead,this,&Server::onReadPendingDatagrams);
    return true;
}

void Server::onNewConnection() {
    QPointer<QTcpSocket> newSocket = this->nextPendingConnection();
    if (newSocket == nullptr) {
        return;
    }
    connect(newSocket, &QTcpSocket::connected, this, &Server::onConnected);
    connect(newSocket,&QTcpSocket::disconnected,this,&Server::onDisconnected);
    connect(newSocket, &QTcpSocket::readyRead, this, &Server::onTcpReadyRead);
    QString socketInfo = generateSocketInfo(*newSocket);
    logger->log(Logger::LogType::NewConnection,
                QString("新连接: ") + socketInfo);
    sockets_.insert(socketInfo, newSocket);
    emit socketsUpdate();
}



Server::~Server() {
    if (!logger.isNull()) {
        delete logger;
    }
    if(!udpSocket_.isNull()){
        delete udpSocket_;
    }
    for (auto it = sockets_.begin(); it != sockets_.end(); it++) {
        delete it.value();
    }
}

void Server::onConnected() {

}

void Server::onDisconnected() {
    auto socket = dynamic_cast<QTcpSocket *>(sender());
    if (socket != nullptr) {
        QString socketInfo = generateSocketInfo(*socket);
        if (sockets_.contains(socketInfo)) {
            sockets_.remove(socketInfo);
            emit socketsUpdate();
            logger->log(Logger::LogType::EndConnection, QString("连接断开: ") + socketInfo);
        }
    }
}

void Server::onTcpReadyRead() {
    QPointer<QTcpSocket> socket = dynamic_cast<QTcpSocket *>(sender());
    if(socket.isNull()){
        return;
    }
    QByteArray data=socket->readAll();
    QString msg=QString::fromUtf8(data);
    QString outputMsg= generateSocketInfo(*socket);

    logger->log(outputMsg+":"+msg);
}

Logger *Server::getLogger() {
    return logger;
}

QString Server::generateSocketInfo(const QAbstractSocket &socket) {
    QString newSocketIp = socket.peerAddress().toString().remove("::ffff:");
    quint16 newSocketPort = socket.peerPort();
    QString socketInfo = newSocketIp + ":" + QString::number(newSocketPort);
    return socketInfo;
}

const QHash<QString, QPointer<QTcpSocket>> &Server::getSockets() {
    return sockets_;
}

void Server::endListen() {
    this->close();
}

void Server::onReadPendingDatagrams() {
    while(udpSocket_->hasPendingDatagrams()){
        QNetworkDatagram datagram=udpSocket_->receiveDatagram();
        processDataGram(qMove(datagram));
    }
}

void Server::processDataGram(const QNetworkDatagram &datagram) {
    qDebug()<<datagram.data()<<"\n";
}

void Server::onBytesWritten(qint64) {

}

void Server::incomingConnection(qintptr handle) {
    ThreadManager& threadManager=ThreadManager::getInstance();
    QPointer<QThread> thread=threadManager.getThread();
    QPointer<Worker> worker=new Worker(handle);
    worker->moveToThread(thread);
    connect(thread,&QThread::started,worker,&Worker::working);
    thread->start();
    emit newConnection();
}





