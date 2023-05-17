#include "../headers/position.h"
position::position() : d_x{0}, d_y{0}
{

}

position::position(int x, int y) : d_x{x}, d_y{y}
{

}


position::position(const position &p) : d_x{p.getX()}, d_y{p.getY()}
{

}

int position::getX() const
{
    return d_x;
}

int position::getY() const
{
    return d_y;
}

void position::setX(int x)
{
    d_x=x;
}

void position::setY(int y)
{
    d_y = y;
}

position& position::operator=(const position& p)
{
    if (this == &p) {
        return *this;  
    }

    d_x = p.getX();
    d_y = p.getY();
    return *this;
}

bool position::operator==(const position& other) const
{
    return (d_x == other.getX()) && (d_y == other.getY());
}

