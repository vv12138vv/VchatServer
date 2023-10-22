//
// Created by jgss9 on 10/22/2023.
//

#ifndef VCHATSERVER_THREAD_MANAGER_H
#define VCHATSERVER_THREAD_MANAGER_H

#include<QObject>
#include<QHash>
#include<QThread>
#include<QPointer>

class ThreadManager : public QObject {
Q_OBJECT

private:
    quint32 defaultThreadCount_ = 10;

    explicit ThreadManager();

    QHash<quint32, QPointer<QThread>> threads_;
public:
    ThreadManager(const ThreadManager &) = delete;

    ThreadManager &operator=(const ThreadManager &) = delete;

    static ThreadManager &getInstance();

    QPointer<QThread> getThread();

    ~ThreadManager() override;
};


#endif //VCHATSERVER_THREAD_MANAGER_H
