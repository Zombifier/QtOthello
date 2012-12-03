#ifndef PIECE_H
#define PIECE_H

class Piece
{
public:
    Piece(short xpos, short ypos) :
        xpos(xpos), ypos(ypos),owner(0) { }
    const short xpos;
    const short ypos;
    short owner;
};

#endif // PIECE_H
