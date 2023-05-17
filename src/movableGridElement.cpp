#include "../headers/movableGridElement.h"
#include "../headers/position.h"


movableGridElement::movableGridElement(const position & pos) : gridElement{pos} , life{true}
{

}

void movableGridElement::setPosition(const position &pos)
{
    d_pos.setX(pos.getX());
    d_pos.setY(pos.getY());
}

bool movableGridElement::getLife()const
{
   return life;
}
   
void movableGridElement::kill()
{
  life = false;
}