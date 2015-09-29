#include "game.h"
#include "controller.h"

// Contructor
// input : controller contr
// Sets the contr variable to contr and sets other values to default
Game::Game(Controller contr): contr(contr), xturn(true), movesLeft(9) {
    for (int i = 0; i < 3 ; i++) {
        for (int j = 0 ; j < 3 ; j++) {
            board[i][j] = 0;
        }
    }
}

// Destructor
Game::~Game(){

}

// mark(int h, int w)
// input: coordinate point (h,w) to mark
// output: -1 - move could not be made
//          0 - move made successfully
//          1 - x wins
//          2 - o wins
//          3 - stalemate
// Marks the set coordinate if possible respective to bool xturn and returns code
//  to dictate board state after move is made

int Game::mark(int h, int w){

    // Checks to see if the move is valid
    if (board[h][w] != 0) {
        return -1;
    }

    // Make the move
    board[h][w] = (xturn ? 1 : 2);

    // reset the xturn variable and decrease moves left
    xturn = !xturn;
    movesLeft--;

    // Check the resulting board state
    // 1. Check if horizontal or vertical win

    // vhS is a switch between vertical and horizontal
    for (int whS = 0 ; vhS < 2 ; vhS++) {
        // Recurse through all three vertical or horizontal possibilities
        for (int c = 0; c < 3; c++) {

            // The starting coordinate for the respective leading square
            int hVal = c*(1 - vhS);
            int wVal = c*vhS;

            // The increments to add to the starting coordinates (note: if starting coords are vertical first, then we add horizontal
            //  and vice-versa)
            int wInc = 1 - vhS;
            int hInc = vhS;

            // Check which type to compare to
            int cto = (xturn ? 1 : 2);

            // Check the three in a row
            if ((board[hVal][wVal] == cto)
              &&(board[hVal + hInc][wVal + wInc] == cto)
              &&(board[hVal + 2*hInc][wVal + 2*wInc] == cto)) {

                // return the correct value
                if (cto == 1) {
                    return 1;
                } else {
                    return 2;
                }

            }
        }
    }

    // 2. check the two accross rows

    for (int bS = 0; bS < 2 ; bS++) {

        int tInc = (bs == 0 ? -1 : 1);
        int bInc = (bs == 0 ? 1 : -1);

        // Check which type to compare to
        int cto = (xturn ? 1 : 2);

        // Check the three in a row
        if ((board[1][1] == cto)
          &&(board[0][1 + tInc] == cto)
          &&(board[2][1 + bInc] == cto)) {

            // return the correct value
            if (cto == 1) {
                return 1;
            } else {
                return 2;
            }

        }
    }

    // returns either 0 or 3 depending on if there are moves left
    return (movesLeft == 0 ? 3 : 0);

}

// clearboard()
// resets the board state to a new game state
void Game::clearboard() {
    for (int i = 0; i < 3 ; i++) {
        for (int j = 0 ; j < 3 ; j++) {
            board[i][j] = 0;
        }
    }
}

// xturn()
// output : bool
// returns true if it is x's turn and false otherwise
bool Game::xturn() {
    return xturn;
}
