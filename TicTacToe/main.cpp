#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    // Create the window
    QApplication a(argc, argv);
    MainWindow w;

    // Format the window
    w.showMaximized();
    w.setFixedSize(200,300);
    w.show();

    return a.exec();
}
