#ifndef PLAYERDIFFICULTLEVEL_H
#define PLAYERDIFFICULTLEVEL_H

#include <iostream>
#include "../headers/player.h"
class interface;
class position;



class playerDifficultLevel : public player
{
public :
    playerDifficultLevel(const position & pos);
    void display(const interface &inter) const override;

    position newPos(int direction) const override;
};



#endif // PLAYERDIFFICULTLEVEL_H