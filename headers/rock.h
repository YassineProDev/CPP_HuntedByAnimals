#ifndef ROCK_H_INCLUDED
#define ROCK_H_INCLUDED

#include <iostream>
#include "../headers/position.h"
#include "../headers/gridElement.h"


class rock : public gridElement
{
public :
    rock(const position & pos);
    void display(const interface &inter) const override;
};




#endif // ROCK_H_INCLUDED


