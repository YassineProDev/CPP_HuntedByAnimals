#include "../headers/cheetah.h"
#include "../headers/rock.h"
#include "../headers/position.h"
#include "../headers/grid.h"
#include "../headers/interface.h"

cheetah::cheetah(const position &pos) : wildAnimal{pos}
{

}

void cheetah::display(const interface &inter) const
{
    inter.displayCheetah();
}

position cheetah::newPos(const position &playerPos, grid &g) const
{
      bool t = false;
      std::vector <position> listPos = listNewPos(playerPos);
      int i =0,e;
      while(i<listPos.size() && t==false)
      {
         e = g.elementAtPosition(listPos[i]);

         if(e!=4 && e!=2 && g.validPosition(listPos[i]))
         {
            t=true;
         }
         i++;
      }
      return listPos[0];
}

std::vector <position> cheetah::listNewPos(const position &playerPos) const
{
     std::vector<position> movementList;
     int Iplayer = playerPos.getX(), Jplayer = playerPos.getY(), Icheetah = d_pos.getX(), Jcheetah = d_pos.getY();


     if(Jcheetah > Jplayer)
     {
         if(Icheetah < Iplayer)
         {
            movementList.push_back(position(getPos().getX() + 1, getPos().getY() - 1));
            movementList.push_back(position(getPos().getX(), getPos().getY() - 1));
            movementList.push_back(position(getPos().getX() + 1, getPos().getY()));
         }
         else if(Icheetah > Iplayer)
         {
            movementList.push_back(position(getPos().getX() - 1, getPos().getY() - 1));
            movementList.push_back(position(getPos().getX(), getPos().getY() - 1));
            movementList.push_back(position(getPos().getX() - 1, getPos().getY()));
         }
         else
         {
            movementList.push_back(position(getPos().getX(), getPos().getY() - 1));
            movementList.push_back(position(getPos().getX() - 1, getPos().getY() - 1));
            movementList.push_back(position(getPos().getX() + 1, getPos().getY() - 1));
         }
     }
     else if(Jcheetah < Jplayer)
     {
         if(Icheetah < Iplayer)
         {
            movementList.push_back(position(getPos().getX() + 1, getPos().getY() + 1));
            movementList.push_back(position(getPos().getX() + 1, getPos().getY()));
            movementList.push_back(position(getPos().getX(), getPos().getY() + 1));
         }
         else if(Icheetah > Iplayer)
         {
            movementList.push_back(position(getPos().getX() - 1, getPos().getY() + 1));
            movementList.push_back(position(getPos().getX() - 1, getPos().getY()));
            movementList.push_back(position(getPos().getX(), getPos().getY() + 1));
         }
         else
         {
            movementList.push_back(position(getPos().getX(), getPos().getY() + 1));
            movementList.push_back(position(getPos().getX() + 1, getPos().getY() + 1));
            movementList.push_back(position(getPos().getX() - 1, getPos().getY() + 1));
         }
     }
     else if(Jcheetah == Jplayer)
     {
         if(Icheetah > Iplayer)
         {
            movementList.push_back(position(getPos().getX() - 1, getPos().getY()));
            movementList.push_back(position(getPos().getX() - 1, getPos().getY() - 1));
            movementList.push_back(position(getPos().getX() - 1, getPos().getY() + 1));
         }
         else if(Icheetah < Iplayer)
         {
            movementList.push_back(position(getPos().getX() + 1, getPos().getY()));
            movementList.push_back(position(getPos().getX() + 1, getPos().getY() - 1));
            movementList.push_back(position(getPos().getX() + 1, getPos().getY() + 1));
         }
     }
     else if(Icheetah == Iplayer)
     {
         if(Jcheetah > Jplayer)
         {
            movementList.push_back(position(getPos().getX(), getPos().getY() - 1));
            movementList.push_back(position(getPos().getX() - 1, getPos().getY() - 1));
            movementList.push_back(position(getPos().getX() + 1, getPos().getY() - 1));
         }
         else if(Jcheetah < Jplayer)
         {
            movementList.push_back(position(getPos().getX(), getPos().getY() + 1));
            movementList.push_back(position(getPos().getX() - 1, getPos().getY() + 1));
            movementList.push_back(position(getPos().getX() + 1, getPos().getY() + 1));
         }
     }
     return movementList;
}