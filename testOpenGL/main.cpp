#include "mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QDesktopWidget wid;
    // Setting title
    w.setWindowTitle("Kevin's OpenGL workspace");
    // Set to center
    w.setGeometry(wid.screen()->width()/2-w.width()/2,wid.screen()->height()/2-w.height()/2 , w.width() , w.height());
    w.setFixedSize(w.width(),w.height());
    w.show();
    return a.exec();
}
