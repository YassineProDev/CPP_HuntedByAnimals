#ifndef GRID_H_INCLUDED
#define GRID_H_INCLUDED

#include "../headers/player.h"
#include "../headers/wildAnimal.h"
#include "../headers/gridElement.h"
#include <memory>
#include <vector>
#include <fstream>
#include <string>


class grid
{
   public :
     grid(int choice, std::string name);
     void gridByDefault();
     void gridImport(std::string nameFile);

     int gridElementAtPosition(position p) const;
     int wildcatAtPosition(position p) const;
     int elementAtPosition(position p) const;
     position getPosPlayer() const;
    

     void movePlayer(int i);
     void movePalyerOn(int situation,position newPos);

     void moveWildcat(int i);
     void moveAllWildact();
     void moveWildcatOn(int situation,position newPos, int i);
     int  caseWildcatAtPosition(position p);

     int getDeadWildAnimalsNumber() const;
     int getPlayerLifeTime() const;
     
     bool gameOver();
     bool playerLife();
     bool wildcatLife();
     void display();

     bool validPosition(position p);

     std::vector<std::unique_ptr<wildAnimal>> wildAnimalsList;
     std::vector<std::unique_ptr<gridElement>> gridElementList;
     std::vector<std::unique_ptr<player>> Player;
     int deadWildAnimalsNumber;
     int playerLifeTime;
     int d_choice;
     std::string nameFile;
     int d_width;
     int d_height;
     int d_mode;

};


#endif // GRID_H_INCLUDED