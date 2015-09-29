#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "clickablelabel.h"
#include "controller.h"
#include <QtCore/QCoreApplication>
#include <QGraphicsScene>

// Constructor
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    // Create the 3 by 3 drawn frame
    QFrame *htline = new QFrame(this);
    htline->setObjectName(QString::fromUtf8("line"));
    htline->setGeometry(QRect(25, 75, 150, 5));
    htline->setFrameShape(QFrame::HLine);

    QFrame *hbline = new QFrame(this);
    hbline->setObjectName(QString::fromUtf8("line"));
    hbline->setGeometry(QRect(25, 125, 150, 5));
    hbline->setFrameShape(QFrame::HLine);

    QFrame *vrline = new QFrame(this);
    vrline->setObjectName(QString::fromUtf8("line"));
    vrline->setGeometry(QRect(75, 25, 5, 150));
    vrline->setFrameShape(QFrame::VLine);

    QFrame *vlline = new QFrame(this);
    vlline->setObjectName(QString::fromUtf8("line"));
    vlline->setGeometry(QRect(125, 25, 5, 150));
    vlline->setFrameShape(QFrame::VLine);

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
    clabel_00 = new ClickableLabel(" ", this, 0, 0, contr);
    clabel_00 -> setGeometry(QRect(QPoint(25, 25), QSize(50, 50)));

    clabel_01 = new ClickableLabel(" ", this, 0, 1, contr);
    clabel_01 -> setGeometry(QRect(QPoint(75, 25), QSize(50, 50)));

    clabel_02 = new ClickableLabel(" ", this, 0, 2, contr);
    clabel_02 -> setGeometry(QRect(QPoint(125, 25), QSize(50, 50)));

    clabel_10 = new ClickableLabel(" ", this, 1, 0, contr);
    clabel_10 -> setGeometry(QRect(QPoint(25, 75), QSize(50, 50)));

    clabel_11 = new ClickableLabel(" ", this, 1, 1, contr);
    clabel_11 -> setGeometry(QRect(QPoint(75, 75), QSize(50, 50)));

    clabel_12 = new ClickableLabel(" ", this, 1, 2, contr);
    clabel_12 -> setGeometry(QRect(QPoint(125, 75), QSize(50, 50)));

    clabel_20 = new ClickableLabel(" ", this, 2, 0, contr);
    clabel_20 -> setGeometry(QRect(QPoint(25, 125), QSize(50, 50)));

    clabel_21 = new ClickableLabel(" ", this, 2, 1, contr);
    clabel_21 -> setGeometry(QRect(QPoint(75, 125), QSize(50, 50)));

    clabel_22 = new ClickableLabel(" ", this, 2, 2, contr);
    clabel_22 -> setGeometry(QRect(QPoint(125, 125), QSize(50, 50)));


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
