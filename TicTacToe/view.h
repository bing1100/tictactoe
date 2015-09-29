#ifndef VIEW_H
#define VIEW_H

#include <string>

class View {

    char board[3][3];

public:

    char getValue(int h, int w);

    void notify(char val, int h, int w);

};

#endif // VIEW_H

