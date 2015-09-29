#ifndef VIEW_H
#define VIEW_H

#include <string>

// DEPRECATED

class MainWindow;

class View {

    // the character board view
    char board[3][3];

    // the window to print to
    MainWindow * w;

public:

    // constructor/destructors
    View(MainWindow * w);
    ~View();

    // print message for the move label
    void printmove(std::string message);

    // print message for the status label
    void printstatus(std::string message);

    // notify the view of a change and print the change to the grid
    void notify(char val, int h, int w);

};

#endif // VIEW_H

