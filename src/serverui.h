//
// Created by jgss9 on 10/15/2023.
//

#ifndef VCHATSERVER_SERVERUI_H
#define VCHATSERVER_SERVERUI_H

#include <QWidget>
#include "server.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ServerUi; }
QT_END_NAMESPACE

class ServerUi : public QWidget {
Q_OBJECT

private:
    Ui::ServerUi *ui;
    QPointer<Server> server;
    quint32 tcpPort=0;
    void initSlots();
public:
    explicit ServerUi(QWidget *parent = nullptr);
    ~ServerUi() override;

private slots:
    void onLog(const QString& logMsg);
    void onInputPort();
    void onServerStartListen();
    void onSocketListUpdate();
};


#endif //VCHATSERVER_SERVERUI_H
