#ifndef MOVABLEGRIDELEMENT_H_INCLUDED
#define MOVABLEGRIDELEMENT_H_INCLUDED

#include "../headers/gridElement.h"
#include <iostream>


class position;
class interface;
class grid;

class movableGridElement : public gridElement
{
public :
   movableGridElement(const position &pos);
   void setPosition(const position &pos);
   void display(const interface &inter) const  override =0;
   bool getLife()const;
   void kill();
protected :
   bool life;

};

#endif // MOVABLEGRIDELEMENT_H_INCLUDED