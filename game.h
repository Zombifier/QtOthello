#ifndef GAME_H
#define GAME_H

#include <vector>

#include "piece.h"
#include "qboard.h"

using namespace std;

class Game
{
    const short gameSize;
    std::vector<QPiece*>* list;
    short turnCount;
public:
    Game(short gameSize, std::vector<QPiece*>* list);
    short greenCount, redCount;

    short turn() const;
    void update();
    bool ended() const;
    bool put(short x, short y, short owner, bool test = false);
    void initialize();
    void reset();
private:
    bool inBound(short x, short y);
    bool placeline(short x, short y, short owner,
                   short xdir, short ydir, bool test = false);
    bool isStuck(short owner);
};

#endif // GAME_H
