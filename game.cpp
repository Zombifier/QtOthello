#include "game.h"
#include "player.h"
#include <iostream>

Game::Game(short gameSize, std::vector<QPiece*>* list) :
    gameSize(gameSize), list(list), turnCount(0)
{
    initialize();
}

void Game::initialize()
{
    short center;
    if(gameSize % 2)
        center = gameSize * gameSize / 2;
    else
        center = gameSize * (gameSize + 1) / 2;
    list->at(center-gameSize-1)->owner = player1;
    list->at(center-gameSize)->owner = player2;
    list->at(center-1)->owner = player2;
    list->at(center)->owner = player1;
}

short Game::turn() const
{
    return turnCount%2 == 0 ? 1 : 2;
}

bool Game::ended() const
{
    if(greenCount == 0 || redCount == 0)
        return true;
    for(auto it = list->begin(); it != list->end(); it++){
        if((*it)->owner == empty)
            return false;
    }
    return true;
}

/*
 *  Updates the blackCount and whiteCount
 */
void Game::update()
{
    greenCount = 0, redCount = 0;
    for(auto it = list->begin(); it != list->end(); it++){
        if((*it)->owner == player1)
            greenCount++;
        if((*it)->owner == player2)
            redCount++;
    }
}

/*
 *  Put a piece a the game board
 *  If test is true, only test if putting is possible
 */
bool Game::put(short x, short y, short owner, bool test)
{
    if(list->at(x+y*gameSize)->owner != empty)
        return false;
    bool success = false;
    success = placeline(x, y, owner, 1, 1,  test) || success;
    success = placeline(x, y, owner, 1, 0,  test) || success;
    success = placeline(x, y, owner, 1, -1, test) || success;
    success = placeline(x, y, owner, 0, 1,  test) || success;
    success = placeline(x, y, owner, 0, -1, test) || success;
    success = placeline(x, y, owner, -1, 1, test) || success;
    success = placeline(x, y, owner, -1, 0, test) || success;
    success = placeline(x, y, owner, -1, -1, test)|| success;
    if(success && !test){
        list->at(x+y*gameSize)->owner = owner;
        turnCount++;
        update();
        if(isStuck(swapPlayer(owner)))
            turnCount++;
    }
    return success;
}

/* Check if the given coodinate is inside the board */
bool Game::inBound(short x, short y)
{
    return x >= 0 && y >= 0 && x < gameSize && y < gameSize;
}

/*
 *  Update the line
 *  If it not possible, return false
 *  If test is true, it does not actually place the line
 */
bool Game::placeline(short x, short y, short owner, short xdir, short ydir, bool test)
{
    std::vector<QPiece*> pieces;
    for(x+=xdir, y+=ydir;
        inBound(x, y) && list->at(x+y*gameSize)->owner == swapPlayer(owner);
        x+=xdir, y+=ydir){
        pieces.push_back(list->at(x+y*gameSize));
    }
    if(pieces.size() == 0)
        return false;
    if(!inBound(x, y) || list->at(x+y*gameSize)->owner == empty)
        return false;
    if(!test){
        for(auto it = pieces.begin(); it != pieces.end(); it++)
            (*it)->owner = owner;
    }
    return true;
}

bool Game::isStuck(short owner)
{
    for(short i = 0; i < gameSize; i++)
        for(short j = 0; j < gameSize; j++)
            if(put(i, j, owner, true))
                return false;
    return true;
}

void Game::reset()
{
    turnCount = 0;
    for(auto it = list->begin(); it != list->end(); it++){
        (*it)->owner = empty;
    }
    initialize();
    update();
}
