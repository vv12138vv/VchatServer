//
// Created by jgss9 on 10/15/2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_ServerUi.h" resolved

#include <QRegularExpression>
#include "serverui.h"
#include "ui_ServerUi.h"


ServerUi::ServerUi(QWidget *parent) :
        QWidget(parent), ui(new Ui::ServerUi) {
    ui->setupUi(this);
    server = new Server(this);
    initSlots();
}

ServerUi::~ServerUi() {
    delete ui;
}
void ServerUi::initSlots() {
//    connect(ui->tcpPortInput, SIGNAL(editingFinished()),this, SLOT(onInputPort()));
    connect(ui->tcpPortInput,&QLineEdit::editingFinished,this,&ServerUi::onInputPort);
    connect(server->getLogger(), SIGNAL(newLog(const QString&)), this, SLOT(onLog(const QString &)));
    connect(ui->serverStartBtn, SIGNAL(clicked(bool)),this, SLOT(onServerStartListen()));
    connect(server, SIGNAL(socketsUpdate()),this,SLOT(onSocketListUpdate()));
}

void ServerUi::onLog(const QString &logMsg) {
    ui->systemTextBrowser->setText(ui->systemTextBrowser->toPlainText() + logMsg + '\n');
    ui->systemTextBrowser->textCursor().movePosition(QTextCursor::End);
}

void ServerUi::onInputPort() {
    QString text=ui->tcpPortInput->text();
    QRegularExpression regExp("^[0-9]+$");//正则表达式
    auto match=regExp.match(text);
    bool isNumber=match.hasMatch();//Todo 已判断是否是纯数字，将来可能需要输入检测
    if(isNumber){
        quint32 port=text.toInt();
        if(port>=65535||port<=1024){
            //Todo 错误
        }
        this->tcpPort=port;
        return;
    }
}

void ServerUi::onServerStartListen() {
    if(tcpPort == 0){
        return;
    }
    if(server->isListening()){
        server->endListen();
        ui->serverStartBtn->setText("Listen");
    }else{
        bool ifListen=server->listenTo(tcpPort);
        if(ifListen){
            ui->serverStartBtn->setText("Stop");
        }
    }
}

void ServerUi::onSocketListUpdate(){
    ui->socketList->clear();
    auto socketList=server->getSockets();
    for(auto it=socketList.begin();it!=socketList.end();it++){
        ui->socketList->addItem(it.key());
    }
}