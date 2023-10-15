//
// Created by jgss9 on 10/15/2023.
//

#include "server.h"

Server::Server(QObject *parent) : QTcpServer(parent) {
    listen(QHostAddress::Any,8888);

}
