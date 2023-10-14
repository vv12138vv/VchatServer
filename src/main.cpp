#include <QApplication>
#include <QPushButton>
#include "qt6clionwiget.h"
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Qt6ClionWiget wiget;
    wiget.resize(800,600);
    wiget.show();
    return QApplication::exec();
}
