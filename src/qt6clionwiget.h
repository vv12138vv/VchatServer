//
// Created by jgss9 on 10/14/2023.
//

#ifndef VCHATSERVER_QT6CLIONWIGET_H
#define VCHATSERVER_QT6CLIONWIGET_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class Qt6ClionWiget; }
QT_END_NAMESPACE

class Qt6ClionWiget : public QWidget {
Q_OBJECT

public:
    explicit Qt6ClionWiget(QWidget *parent = nullptr);

    ~Qt6ClionWiget() override;

private:
    Ui::Qt6ClionWiget *ui;
};


#endif //VCHATSERVER_QT6CLIONWIGET_H
