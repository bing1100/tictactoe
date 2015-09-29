#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>


class ClickableLabel;
class Controller;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    // Constructor/destuctor
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    // print message for the move label
    void printmove(const QString& message);

    // print message for the status label
    void printstatus(const QString& message);

public slots:

    // Catch when the clearboard button is clicked
    void clearboard();

signals:

    // Signals the controller/game to clear the board
    void clearboard(int type, int h = 4, int w = 4);

private:

    // Labels
    QLabel * status;
    QLabel * move;

    // Pushbuttons
    QPushButton * cboard;

    // ClickableLabels
    ClickableLabel * clabel_00;
    ClickableLabel * clabel_01;
    ClickableLabel * clabel_02;
    ClickableLabel * clabel_10;
    ClickableLabel * clabel_11;
    ClickableLabel * clabel_12;
    ClickableLabel * clabel_20;
    ClickableLabel * clabel_21;
    ClickableLabel * clabel_22;

    // the character board view
    char board[3][3];

    // the window to print to
    Controller * contr;

};

#endif // MAINWINDOW_H
