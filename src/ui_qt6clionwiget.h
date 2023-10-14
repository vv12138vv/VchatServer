/********************************************************************************
** Form generated from reading UI file 'qt6clionwiget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT6CLIONWIGET_H
#define UI_QT6CLIONWIGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Qt6ClionWiget
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *Qt6ClionWiget)
    {
        if (Qt6ClionWiget->objectName().isEmpty())
            Qt6ClionWiget->setObjectName("Qt6ClionWiget");
        Qt6ClionWiget->resize(600, 415);
        pushButton = new QPushButton(Qt6ClionWiget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(110, 90, 75, 24));
        pushButton_2 = new QPushButton(Qt6ClionWiget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(410, 90, 75, 24));

        retranslateUi(Qt6ClionWiget);

        QMetaObject::connectSlotsByName(Qt6ClionWiget);
    } // setupUi

    void retranslateUi(QWidget *Qt6ClionWiget)
    {
        Qt6ClionWiget->setWindowTitle(QCoreApplication::translate("Qt6ClionWiget", "Qt6ClionWiget", nullptr));
        pushButton->setText(QCoreApplication::translate("Qt6ClionWiget", "OK", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Qt6ClionWiget", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Qt6ClionWiget: public Ui_Qt6ClionWiget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT6CLIONWIGET_H
