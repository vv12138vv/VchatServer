//
// Created by jgss9 on 10/15/2023.
//

#ifndef VCHATSERVER_SERVER_H
#define VCHATSERVER_SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

class Server : public QTcpServer {
Q_OBJECT

public:
    explicit Server(QObject *parent = nullptr);

private:
    QTcpSocket socket;
signals:

public slots:
};


#endif //VCHATSERVER_SERVER_H
