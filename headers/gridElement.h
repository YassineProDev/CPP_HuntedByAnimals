#ifndef GRIDELEMENT_H_INCLUDED
#define GRIDELEMENT_H_INCLUDED
#include "../headers/position.h"

class interface;

class gridElement
{
public :
   virtual ~gridElement() = default;
   gridElement(const position &pos);
   position getPos() const;
   virtual void display(const interface &inter) const=0;

protected :
    position d_pos;
};

#endif // GRIDELEMENT_H_INCLUDED
