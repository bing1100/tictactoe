#ifndef GAME_H
#define GAME_H

class Controller;

class Game {

    // The Game Board
    int board[3][3];

    // The controller
    Controller contr;

    // Bool value to keep track of turns
    bool xturn;

    // keep track of moves left
    int movesLeft;

public:

    // Constructor/Destructor
    Game(Controller contr);
    ~Game();

    // Mark the board at h and w with either o or x depending on xturn
    int mark(int h, int w);

    // Reset the board state
    void clearboard();

    // Get the turn
    bool xturn();

};

#endif // GAME_H

