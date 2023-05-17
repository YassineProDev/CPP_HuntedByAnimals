#include "../headers/playerDifficultLevel.h"
#include "../headers/interface.h"
#include "../headers/position.h"

playerDifficultLevel::playerDifficultLevel(const position & pos) : player{pos}
{

}

void playerDifficultLevel::display(const interface &inter) const
{
    inter.displayPlayerDifficultLevel();
}

position playerDifficultLevel::newPos(int direction) const
{
    if(direction==8)
    {
        return position {getPos().getX()-1, getPos().getY()};
    }
    if(direction==2)
    {
       return position {getPos().getX()+1, getPos().getY()};
    }
    if(direction==6)
    {
       return position {getPos().getX(), getPos().getY()+1};
    }
    if(direction==4)
    {
       return position {getPos().getX(), getPos().getY()-1};
    }
    return position{-1,-1};
}