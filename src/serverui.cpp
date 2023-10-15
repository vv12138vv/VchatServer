//
// Created by jgss9 on 10/15/2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_ServerUi.h" resolved

#include "serverui.h"
#include "ui_ServerUi.h"


ServerUi::ServerUi(QWidget *parent) :
        QWidget(parent), ui(new Ui::ServerUi) {
    ui->setupUi(this);
}

ServerUi::~ServerUi() {
    delete ui;
}
