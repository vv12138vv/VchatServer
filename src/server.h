//
// Created by jgss9 on 10/15/2023.
//

#ifndef VCHATSERVER_SERVER_H
#define VCHATSERVER_SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include<QDebug>
#include <QPointer>
#include"logger.h"

class Server : public QTcpServer {
Q_OBJECT

private:
    QPointer<Logger> logger;
    QHash<QString,QPointer<QTcpSocket>> sockets_;//socket记录
public:
    explicit Server(QObject *parent = nullptr);
    Logger* getLogger();
    bool listenTo(quint32 port);
    ~Server() override;
    static QString generateSocketInfo(const QTcpSocket& socket);

public slots:
    void onConnected();
    void onDisconnected();
    void onDataReady();
    void onBytesWritten(qint64);
private slots:

    void onNewConnection();

};


#endif //VCHATSERVER_SERVER_H
