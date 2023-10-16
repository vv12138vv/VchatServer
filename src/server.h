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

class Server : public QTcpServer {
Q_OBJECT

private:
    QVector<QPointer<QTcpSocket>> sockets_;

    void logger(const QString& logMsg);

public:
    explicit Server(QObject *parent = nullptr);

    bool listenTo(quint32 port);

signals:

    void newLog(const QString& logMsg);

public slots:

private slots:

    void onNewConnection();

    void onReceiveMsg();
};


#endif //VCHATSERVER_SERVER_H
