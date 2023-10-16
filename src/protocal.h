//
// Created by jgss9 on 10/16/2023.
//

#ifndef VCHATSERVER_PROTOCAL_H
#define VCHATSERVER_PROTOCAL_H


#include <QString>
#include <QHostAddress>
#include <QDateTime>

struct LoginReq {
    QString username;
    QHostAddress hostAddress;
    quint16 port;
};
struct LoginResp {
    bool ifAccept;
    quint16 port;
};
struct UserInfo {
    QString username;
    QHostAddress hostAddress;
    quint16 port;
};
struct GetUsersResp{
    QList<UserInfo> users;
};
struct LogoutReq{
    QString username;
    QHostAddress hostAddress;
    quint16 port;
};
struct LogoutResp{
    QString username;
    QHostAddress hostAddress;
    quint16 port;
};
struct TransMsg{
    QDateTime currentTime;
    QString username;
    QString msg;
};

#endif //VCHATSERVER_PROTOCAL_H
