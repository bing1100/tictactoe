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
            graphicalDisplay->printstatus("not a valid move");
        } else if (ret == 1) {
            gameBoard->clearboard();
            graphicalDisplay->printmove("X to move");
            graphicalDisplay->printstatus("x wins! Starting new game");
        } else if (ret == 2) {
            gameBoard->clearboard();
            graphicalDisplay->printmove("X to move");
            graphicalDisplay->printstatus("o wins! Starting new game");
        } else if (ret == 3) {
            gameBoard->clearboard();
            graphicalDisplay->printmove("X to move");
            graphicalDisplay->printstatus("Tie! Starting new game");
        } else {
            if (gameBoard->getxturn()) {
                graphicalDisplay->printmove("X to move");
                graphicalDisplay->printstatus("");
            } else {
                graphicalDisplay->printmove("O to move");
                graphicalDisplay->printstatus("");
            }
        }

    }
}

void Controller::emitnotify(int val, int h, int w) {
    if (val == 0) {
        emit notify(" ", h, w);
    } else if (val == 1) {
        emit notify("o", h, w);
    } else if (val == 2) {
        emit notify("x", h, w);
    }
}
