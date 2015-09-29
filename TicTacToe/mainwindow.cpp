#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "clickablelabel.h"
#include "controller.h"
#include <QtCore/QCoreApplication>

// Constructor
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    // Create a new controller object
    contr = new Controller(this);

    // Create labels and set location
    status = new QLabel("", this);
    status -> setGeometry(QRect(QPoint(0, 200), QSize(200, 15)));
    status -> setAlignment(Qt::AlignCenter);
    move = new QLabel("x to move", this);
    move -> setGeometry(QRect(QPoint(0, 230), QSize(200, 15)));
    move -> setAlignment(Qt::AlignCenter);

    // Create buttons and connect with controller
    cboard = new QPushButton("new game", this);
    cboard -> setGeometry(QRect(QPoint(50, 260), QSize(100, 20)));
    connect(cboard, SIGNAL(released()), this, SLOT(clearboard()));
    connect(this, SIGNAL(clearboard(int, int, int)), contr, SLOT(catchclick(int, int, int)));


    // Create all clickablelabels, set the geometry, and set the correct connect
    clabel_00 = new ClickableLabel(" ", this, 0, 0);
    clabel_00 -> setGeometry(QRect(QPoint(26, 26), QSize(48, 48)));
    clabel_00 -> setAlignment(Qt::AlignCenter);
    QObject::connect(contr    , SIGNAL(notify(const QString&, int, int))
                    ,clabel_00, SLOT(setval(const QString&, int, int)));
    QObject::connect(clabel_00, SIGNAL(clicked(int, int, int))
                    ,contr    , SLOT(catchclick(int, int, int)));

    clabel_01 = new ClickableLabel(" ", this, 0, 1);
    clabel_01 -> setGeometry(QRect(QPoint(76, 26), QSize(48, 48)));
    clabel_01 -> setAlignment(Qt::AlignCenter);
    QObject::connect(contr    , SIGNAL(notify(const QString&, int, int))
                    ,clabel_01, SLOT(setval(const QString&, int, int)));
    QObject::connect(clabel_01, SIGNAL(clicked(int, int, int))
                    ,contr    , SLOT(catchclick(int, int, int)));

    clabel_02 = new ClickableLabel(" ", this, 0, 2);
    clabel_02 -> setGeometry(QRect(QPoint(126, 26), QSize(48, 48)));
    clabel_02 -> setAlignment(Qt::AlignCenter);
    QObject::connect(contr    , SIGNAL(notify(const QString&, int, int))
                    ,clabel_02, SLOT(setval(const QString&, int, int)));
    QObject::connect(clabel_02, SIGNAL(clicked(int, int, int))
                    ,contr    , SLOT(catchclick(int, int, int)));

    clabel_10 = new ClickableLabel(" ", this, 1, 0);
    clabel_10 -> setGeometry(QRect(QPoint(26, 76), QSize(48, 48)));
    clabel_10 -> setAlignment(Qt::AlignCenter);
    QObject::connect(contr    , SIGNAL(notify(const QString&, int, int))
                    ,clabel_10, SLOT(setval(const QString&, int, int)));
    QObject::connect(clabel_10, SIGNAL(clicked(int, int, int))
                    ,contr    , SLOT(catchclick(int, int, int)));

    clabel_11 = new ClickableLabel(" ", this, 1, 1);
    clabel_11 -> setGeometry(QRect(QPoint(76, 76), QSize(48, 48)));
    clabel_11 -> setAlignment(Qt::AlignCenter);
    QObject::connect(contr    , SIGNAL(notify(const QString&, int, int))
                    ,clabel_11, SLOT(setval(const QString&, int, int)));
    QObject::connect(clabel_11, SIGNAL(clicked(int, int, int))
                    ,contr    , SLOT(catchclick(int, int, int)));

    clabel_12 = new ClickableLabel(" ", this, 1, 2);
    clabel_12 -> setGeometry(QRect(QPoint(126, 76), QSize(48, 48)));
    clabel_12 -> setAlignment(Qt::AlignCenter);
    QObject::connect(contr    , SIGNAL(notify(const QString&, int, int))
                    ,clabel_12, SLOT(setval(const QString&, int, int)));
    QObject::connect(clabel_12, SIGNAL(clicked(int, int, int))
                    ,contr    , SLOT(catchclick(int, int, int)));

    clabel_20 = new ClickableLabel(" ", this, 2, 0);
    clabel_20 -> setGeometry(QRect(QPoint(26, 126), QSize(48, 48)));
    clabel_20 -> setAlignment(Qt::AlignCenter);
    QObject::connect(contr    , SIGNAL(notify(const QString&, int, int))
                    ,clabel_20, SLOT(setval(const QString&, int, int)));
    QObject::connect(clabel_20, SIGNAL(clicked(int, int, int))
                    ,contr    , SLOT(catchclick(int, int, int)));

    clabel_21 = new ClickableLabel(" ", this, 2, 1);
    clabel_21 -> setGeometry(QRect(QPoint(76, 126), QSize(48, 48)));
    clabel_21 -> setAlignment(Qt::AlignCenter);
    QObject::connect(contr    , SIGNAL(notify(const QString&, int, int))
                    ,clabel_21, SLOT(setval(const QString&, int, int)));
    QObject::connect(clabel_21, SIGNAL(clicked(int, int, int))
                    ,contr    , SLOT(catchclick(int, int, int)));

    clabel_22 = new ClickableLabel(" ", this, 2, 2);
    clabel_22 -> setGeometry(QRect(QPoint(126, 126), QSize(48, 48)));
    clabel_22 -> setAlignment(Qt::AlignCenter);
    QObject::connect(contr    , SIGNAL(notify(const QString&, int, int))
                    ,clabel_22, SLOT(setval(const QString&, int, int)));
    QObject::connect(clabel_22, SIGNAL(clicked(int, int, int))
                    ,contr    , SLOT(catchclick(int, int, int)));

}

// Calls the board clear
void MainWindow::clearboard() {
    emit clearboard(0, 0, 0);
}

// Print to the move label with message
void MainWindow::printmove(const QString& message) {
    move->setText(message);
}

// Print to the status label with message
void MainWindow::printstatus(const QString& message) {
    status->setText(message);
}

// Destructor
MainWindow::~MainWindow()
{
}
