#ifndef MENU_H
#define MENU_H
#include <iostream>
#include "../headers/grid.h"
#include "../headers/interface.h"
#include <vector>
#include <memory>
#include <string>

class menu
{
   public :
    menu();
    int choice();
    std::string nameFile();
    void start();
};


#endif // MENU_H