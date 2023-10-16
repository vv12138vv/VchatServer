//
// Created by vv12138vv on 10/15/2023.
//

#include "server.h"

#include <utility>

Server::Server(QObject *parent) : QTcpServer(parent) {
}


bool Server::listenTo(quint32 port) {
    if (!this->listen(QHostAddress::Any, port)) {
        //Todo need error log
    }
    //Todo need log
    logger(QString("成功监听端口：%1").arg(port));
    connect(this, SIGNAL(newConnection()), this, SLOT(onNewConnection()));
    return true;
}

void Server::onNewConnection() {
//    QPointer<QTcpSocket> newSocket = this->nextPendingConnection();
//    connect(newSocket, SIGNAL(newMsgReceived()), this, SLOT(onReceiveMsg));
//    connect(newSocket, SIGNAL(disconnected()), this, SLOT(onDistconnectd()));
//    sockets_.push_back(newSocket);
}

void Server::logger(const QString& logMsg){
    emit newLog(logMsg);
}

void Server::onReceiveMsg() {

}




