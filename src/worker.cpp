//
// Created by jgss9 on 10/22/2023.
//

#include "worker.h"


Worker::Worker(qintptr socketDescriptor, QObject *parent) {

}

void Worker::working() {
    qDebug()<<QThread::currentThread()<<"start"<<"\n";
    qDebug()<<QThread::currentThread()<<"end"<<"\n";

}

