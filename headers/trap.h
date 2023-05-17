#ifndef TRAP_H
#define TRAP_H

#include <iostream>
#include "../headers/gridElement.h"
#include "../headers/position.h"

class interface;
class position;

class trap : public gridElement
{
public :
    trap(const position & pos);
    void display(const interface &inter) const override;
};




#endif // TRAP_H