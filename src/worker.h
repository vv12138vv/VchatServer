//
// Created by jgss9 on 10/22/2023.
//

#ifndef VCHATSERVER_WORKER_H
#define VCHATSERVER_WORKER_H
#include<QObject>
#include<QTcpSocket>
#include<QPointer>
#include<QThread>

class Worker: public QObject{
Q_OBJECT
private:
    QPointer<QTcpSocket> tcpSocket_;
public:
    explicit Worker(qintptr socketDescriptor,QObject* parent= nullptr);
public slots:
    void working();
};


#endif //VCHATSERVER_WORKER_H
