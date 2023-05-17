#include "../headers/gridElement.h"



gridElement::gridElement(const position &pos) : d_pos{pos}
{

}

position gridElement::getPos() const
{
    return d_pos;
}



