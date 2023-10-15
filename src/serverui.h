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

public:
    explicit ServerUi(QWidget *parent = nullptr);

    ~ServerUi() override;

private:
    Ui::ServerUi *ui;
    Server server;
};


#endif //VCHATSERVER_SERVERUI_H
