//
// Created by vv12138vv on 10/15/2023.
//

#include "server.h"

#include <utility>

Server::Server(QObject *parent) : QTcpServer(parent) {
    logger = new Logger(this);
    udpSocket_=new QUdpSocket(this);
}


bool Server::listenTo(quint32 port) {
    if (!this->listen(QHostAddress::AnyIPv4, port)) {
        //Todo need error log
        return false;
    }
    udpSocket_->bind(QHostAddress::AnyIPv4,port+1);
    logger->log(Logger::LogType::StartListen, QString("Tcp成功监听端口：%1").arg(port));
    logger->log(Logger::LogType::StartListen, QString("Ucp成功监听端口：%1").arg(port+1));
//    connect(this, SIGNAL(newConnection()), this, SLOT(onNewConnection()));
    connect(this, &Server::newConnection, this, &Server::onNewConnection);
    connect(udpSocket_,&QUdpSocket::readyRead,this,&Server::onReadPendingDatagrams);
//    connect(udpSocket_, SIGNAL(readyRead()),this, SLOT(onReadPendingDatagrams()));
    return true;
}

void Server::onNewConnection() {
    QPointer<QTcpSocket> newSocket = this->nextPendingConnection();
    if (newSocket == nullptr) {
        return;
    }
//    connect(newSocket, SIGNAL(connected()), this, SLOT(onConnected()));
    connect(newSocket, &QTcpSocket::connected, this, &Server::onConnected);
//    connect(newSocket, SIGNAL(disconnected()), this, SLOT(onDisconnected()));
    connect(newSocket,&QTcpSocket::disconnected,this,&Server::onDisconnected);
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

void Server::onReadyRead() {

}

void Server::onBytesWritten(qint64) {

}

Logger *Server::getLogger() {
    return logger;
}

QString Server::generateSocketInfo(const QTcpSocket &socket) {
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
    qDebug()<<"receive"<<"\n";
}





