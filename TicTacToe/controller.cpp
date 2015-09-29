#include "game.h"
#include "controller.h"
#include "view.h"
#include "mainwindow.h"

// constructor
Controller::Controller(MainWindow * w): graphicalDisplay(w) {
    gameBoard = new Game(this);
}

// destructor
Controller::~Controller() {

}

// click(int type, int h, int w)
// input: coordinates where the player clicked
// clicks on the coordinate spot and notifies view to print messages
void Controller::catchclick(int type, int h, int w) {

    // If the type of the click is a
    if (type == 0) {
        gameBoard->clearboard();
        graphicalDisplay->printmove("X to move");
        graphicalDisplay->printstatus("New game");
    } else {

        int ret = gameBoard->mark(h, w);

        if (ret == -1) {
            graphicalDisplay->printmove("not a valid move");
        } else if (ret == 1) {
            graphicalDisplay->printmove("");
            graphicalDisplay->printstatus("x wins! Please play again!");
        } else if (ret == 2) {
            graphicalDisplay->printmove("");
            graphicalDisplay->printstatus("o wins! Please play again");
        } else if (ret == 3) {
            graphicalDisplay->printmove("");
            graphicalDisplay->printstatus("Tie! Please play again");
        } else {
            if (gameBoard->getxturn()) {
                graphicalDisplay->printmove("X to move");
            } else {
                graphicalDisplay->printmove("O to move");
            }
        }

    }
}

void Controller::emitnotify(int val, int h, int w) {
    if (val == 0) {
        emit notify(" ", h, w);
    } else if (val == 1) {
        emit notify("x", h, w);
    } else if (val == 2) {
        emit notify("o", h, w);
    }
}
