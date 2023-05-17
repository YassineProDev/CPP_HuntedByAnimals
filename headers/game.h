#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "../headers/grid.h"
#include "../headers/interface.h"
#include <vector>
#include <memory>
class game
{
   public :
    game(int choice, std::string name);
    void play();

  private :
    grid gameGrid;
};





#endif // GAME_H