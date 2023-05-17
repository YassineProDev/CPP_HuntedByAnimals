#ifndef PLAYERNORMALLEVEL_H
#define PLAYERNORMALLEVEL_H

#include <iostream>
#include "../headers/player.h"
class interface;
class position;



class playerNormalLevel : public player
{
public :
    playerNormalLevel(const position & pos);
    void display(const interface &inter) const override;

    position newPos(int direction) const override;
};



#endif // PLAYERNORMALLEVEL_H