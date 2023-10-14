//
// Created by jgss9 on 10/14/2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Qt6ClionWiget.h" resolved

#include "qt6clionwiget.h"
#include "ui_qt6clionwiget.h"


Qt6ClionWiget::Qt6ClionWiget(QWidget *parent) :
        QWidget(parent), ui(new Ui::Qt6ClionWiget) {
    ui->setupUi(this);
}

Qt6ClionWiget::~Qt6ClionWiget() {
    delete ui;
}
