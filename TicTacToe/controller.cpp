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

    // If the the new game button is clicked, clear the board
    if (type == 0) {
        gameBoard->clearboard();
        graphicalDisplay->printmove("X to move");
        graphicalDisplay->printstatus("New game");

    // If the button clicked was part of the game
    } else {

        // Get the return value of marking the square with the respective color
        int ret = gameBoard->mark(h, w);

        // If the return value is -1, invalid move
        if (ret == -1) {
            graphicalDisplay->printmove("not a valid move");

        // If the return value is 1, then x is the winner
        } else if (ret == 1) {
            graphicalDisplay->printmove("");
            graphicalDisplay->printstatus("x wins! Please play again!");

        // If the return value is 2, then o is the winner
        } else if (ret == 2) {
            graphicalDisplay->printmove("");
            graphicalDisplay->printstatus("o wins! Please play again");

        // If the return value is 3, then there is a tie
        } else if (ret == 3) {
            graphicalDisplay->printmove("");
            graphicalDisplay->printstatus("Tie! Please play again");

        // If the return value is 0 that means move has been made and the next
        //  player needs to input thier move
        } else {

            // Checks which string to print based on who's move it is
            if (gameBoard->getxturn()) {
                graphicalDisplay->printmove("X to move");
            } else {
                graphicalDisplay->printmove("O to move");
            }
        }

    }
}

// emitnotify
// input: val - the value to be updated to
//        (h,w) - the coordinate that needs to be updated
// Emits the notify signal with val updated to its QString counterpart
void Controller::emitnotify(int val, int h, int w) {
    if (val == 0) {
        emit notify(" ", h, w);
    } else if (val == 1) {
        emit notify("X", h, w);
    } else if (val == 2) {
        emit notify("O", h, w);
    }
}
