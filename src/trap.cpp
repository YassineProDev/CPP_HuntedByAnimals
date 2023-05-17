#include "../headers/trap.h"
#include "../headers/interface.h"


trap::trap(const position & pos) : gridElement{pos}
{

}

void trap::display(const interface &inter) const
{
    inter.displayTrap();
}

