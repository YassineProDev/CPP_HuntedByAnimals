#ifndef INTERFACET_H_INCLUDED
#define INTERFACET_H_INCLUDED

#include <iostream>
class grid;
class interface
{
public :
    interface();
    void displayGrid(const grid& ) const ;
    char displayCheetah() const ;
    char displayLion() const ;
    char displayTrap() const ;
    char displayRock() const ;
    char displayPlayerDifficultLevel() const ;
    char displayPlayerNormalLevel() const ;
};




#endif // INTERFACET_H_INCLUDED
