#include "../headers/playerNormalLevel.h"
#include "../headers/interface.h"
#include "../headers/position.h"

playerNormalLevel::playerNormalLevel(const position & pos) : player{pos}
{

}

void playerNormalLevel::display(const interface &inter) const
{
    inter.displayPlayerNormalLevel();
}

position playerNormalLevel::newPos(int direction) const
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
    if(direction==7)
    {
       return position {getPos().getX()-1, getPos().getY()-1};
    }
    if(direction==9)
    {
       return position {getPos().getX()-1,getPos().getY()+1};
    }
    if(direction==1)
    {
       return position {getPos().getX()+1, getPos().getY()-1};
    }
    if(direction==3)
    {
       return position {getPos().getX()+1, getPos().getY()+1};
    }
    return position{-1,-1};
}