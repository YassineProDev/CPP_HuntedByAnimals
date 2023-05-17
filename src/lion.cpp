#include "../headers/lion.h"
#include "../headers/rock.h"
#include "../headers/position.h"
#include "../headers/grid.h"
#include "../headers/interface.h"

lion::lion(const position &pos) : wildAnimal{pos}
{

}

void lion::display(const interface &inter) const
{
    inter.displayLion();
}



position lion::newPos(const position &playerPos, grid &g) const 
{
      bool t = false;
      std::vector <position> listPos = listNewPos(playerPos);
      int i =0, e;
      while(i<listPos.size() && t==false)
      {
         e = g.elementAtPosition(listPos[i]);
         if(e!=3 && e!=2 && g.validPosition(listPos[i]))
         {
            t=true;
         }
         i++;
      }
      return listPos[i-1];
}


 std::vector <position> lion::listNewPos(const position &playerPos) const
{
     std::vector<position> movementList;
     int Iplayer = playerPos.getX(), Jplayer = playerPos.getY(), Ilion = d_pos.getX(), Jlion = d_pos.getY();
     if(Jlion > Jplayer)
     {
         if(Ilion < Iplayer)
         {
            movementList.push_back(position(getPos().getX(), getPos().getY() - 1));
            movementList.push_back(position(getPos().getX() + 1, getPos().getY()));
         }
         else if(Ilion > Iplayer)
         {
            movementList.push_back(position(getPos().getX(), getPos().getY() - 1));
            movementList.push_back(position(getPos().getX() - 1, getPos().getY())); 
         }
         else
         {
            movementList.push_back(position(getPos().getX(), getPos().getY() - 1));
         }
     }
     else if(Jlion < Jplayer)
     {
         if(Ilion < Iplayer)
         {
           movementList.push_back(position(getPos().getX() + 1, getPos().getY()));
           movementList.push_back(position(getPos().getX(), getPos().getY() + 1)); 
         }
         else if(Ilion > Iplayer)
         {
            movementList.push_back(position(getPos().getX() - 1, getPos().getY()));
            movementList.push_back(position(getPos().getX(), getPos().getY() + 1));
         }
         else
         {
            movementList.push_back(position(getPos().getX(), getPos().getY() + 1));
         }
     }
     else if(Jlion == Jplayer)
     {
         if(Ilion > Iplayer)
         {
            movementList.push_back(position(getPos().getX() - 1, getPos().getY()));
            movementList.push_back(position(getPos().getX() , getPos().getY()+1));
            movementList.push_back(position(getPos().getX() , getPos().getY()-1));
         }
         else if (Ilion < Iplayer)
         {
            movementList.push_back(position(getPos().getX() + 1, getPos().getY()));
            movementList.push_back(position(getPos().getX() , getPos().getY()+1));
            movementList.push_back(position(getPos().getX() , getPos().getY()-1));
         }
     }
     else if(Ilion == Iplayer)
     {
         if(Jlion > Jplayer)
         {
           movementList.push_back(position(getPos().getX(), getPos().getY() - 1));
         }
         else if(Jlion < Jplayer)
         {
           movementList.push_back(position(getPos().getX(), getPos().getY() + 1));
         }
     }
          return movementList;
}















