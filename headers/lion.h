#ifndef LION_H_INCLUDED
#define LION_H_INCLUDED

#include "../headers/wildAnimal.h"
#include <iostream>

class interface;
class position;
class grid;

class lion : public wildAnimal
{
public:
    lion(const position & pos);
    void display(const interface &inter) const override;

    std::vector <position> listNewPos(const position &playerPos) const override;
    position newPos(const position &playerPos, grid &g) const override;
};



#endif // LION_H_INCLUDED
