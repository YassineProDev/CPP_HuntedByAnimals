#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <iostream>
#include "../headers/movableGridElement.h"
class position;
class interface;



class player : public movableGridElement
{
    public :
    player(const position & pos);
    void display(const interface &inter) const override =0;

    virtual position newPos(int direction) const=0;
};



#endif // PLAYER_H_INCLUDED