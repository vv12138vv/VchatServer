//
// Created by jgss9 on 10/22/2023.
//

#include "thread_manager.h"

ThreadManager::ThreadManager() {
    for(int i=0;i<defaultThreadCount_;i++){
        QPointer<QThread> temp=new QThread(this);//QThread负责管理线程，但QThread本身位于主线程
        threads_.insert(i,temp);
    }
}

ThreadManager& ThreadManager::getInstance() {
    static ThreadManager instance_;
    return instance_;
}

ThreadManager::~ThreadManager() {//销毁线程
    for(auto& thread:threads_){
        if(!thread.isNull()&&thread->isRunning()){
            thread->quit();
            thread->wait();
        }
        delete thread;
    }
}

QPointer<QThread> ThreadManager::getThread() {
    return threads_.value(0);
}
