#ifndef CONTROLLER_H
#define CONTROLLER_H

class Game;
class View;

class Controller {

    // The game and view objects
    Game gameBoard;
    View graphicalDisplay;

public:

    // Constructors/destructors
    Controller();
    ~Controller();

    // Main click function
    void click(int h, int w);

    // Notify function for game object to call
    void notify(int val, int h, int w);

};

#endif // CONTROLLER_H

