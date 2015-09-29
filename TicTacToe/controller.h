#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>

class Game;
class View;
class MainWindow;

class Controller: public QObject {

    Q_OBJECT

    // The game and view objects
    Game * gameBoard;
    MainWindow * graphicalDisplay;

public slots:
    // Main play function
    void catchclick(int type, int h, int w);

signals:

    void notify(const QString& ch, int h, int w);

public:

    // Constructors/destructors
    Controller(MainWindow * w);
    ~Controller();



    // Notify function for game object to call
    void emitnotify(int val, int h, int w);

};

#endif // CONTROLLER_H

