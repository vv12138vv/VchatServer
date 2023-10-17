//
// Created by vv12138vv on 10/15/2023.
//

#ifndef VCHATSERVER_SERVER_H
#define VCHATSERVER_SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include<QDebug>
#include <QPointer>
#include"logger.h"
#include<QUdpSocket>

class Server : public QTcpServer {
Q_OBJECT

private:
    QPointer<Logger> logger;
    QHash<QString,QPointer<QTcpSocket>> sockets_;//socket记录
    QPointer<QUdpSocket> udpSocket_;
public:
    explicit Server(QObject *parent = nullptr);
    ~Server() override;
    Logger* getLogger();
    bool listenTo(quint32 port);
    void endListen();
    static QString generateSocketInfo(const QTcpSocket& socket);
    const QHash<QString,QPointer<QTcpSocket>>& getSockets();
    signals:
    void socketsUpdate();

public slots:
    void onConnected();
    void onDisconnected();
    void onReadyRead();
    void onBytesWritten(qint64);
    void onNewConnection();
    void onReadPendingDatagrams();
private slots:


};


#endif //VCHATSERVER_SERVER_H
