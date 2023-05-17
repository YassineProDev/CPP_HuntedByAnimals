
#ifndef WILDCAT_H_INCLUDED
#define WILDCAT_H_INCLUDED

#include "../headers/movableGridElement.h"
#include <iostream>
#include <vector>


class position;
class elements;
class interface;


class wildAnimal : public movableGridElement
{
public :
    wildAnimal(const position & pos);
    void display(const interface &inter) const override=0;

    
    virtual std::vector <position> listNewPos(const position &posJoueur) const=0;
    virtual position newPos(const position &posJoueur, grid &g) const=0; //, grid &g

};




#endif // WILDCAT_H_INCLUDED
