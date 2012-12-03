#include "othello.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    short gameSize;
    if(argc == 2)
        gameSize = atoi(argv[1]);
    else if(argc == 1)
        gameSize = 8;
    else{
        std::cout<<"Usage: Othello [size of game]\n";
        return 0;
    }
    Othello* w = new Othello(0, gameSize);

    w->show();
    return a.exec();
}
