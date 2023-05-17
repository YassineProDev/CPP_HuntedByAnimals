#include "../headers/rock.h"
#include "../headers/interface.h"

rock::rock(const position & pos) : gridElement{pos}
{

}


void rock::display(const interface &inter) const
{
    inter.displayRock();
}

