#include <QApplication>
#include <QPushButton>
#include "serverui.h"
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    ServerUi serverUi;
    return QApplication::exec();
}
