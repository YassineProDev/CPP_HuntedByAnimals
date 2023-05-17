#include "../headers/game.h"
#include "../headers/wildAnimal.h"
#include "../headers/cheetah.h"
#include "../headers/lion.h"
#include "../headers/rock.h"
#include "../headers/trap.h"
#include "../headers/playerNormalLevel.h"
#include "../headers/player.h"
#include "../headers/gridElement.h"
#include "../headers/grid.h"
#include "../headers/interface.h"




game::game(int choice, std::string name) : gameGrid{choice,name}
{
    play();
    
}

void game::play()
{
     int direction;
     gameGrid.display();
     while(gameGrid.gameOver()==false)
     {
        std::cout<<std::endl;
        std::cout<<"SCORE :    Number of rounds : "<<gameGrid.getPlayerLifeTime()<<"    Number of dead wilcats : "<<gameGrid.getDeadWildAnimalsNumber()<<std::endl;
        std::cout<<"Choose the number corresponding to the direction you want to take :"<<std::endl;

        if(gameGrid.d_mode == 1)
        {
          do 
          {
              std::cout<<"           ......."<<std::endl;
              std::cout<<"           . 789 ."<<std::endl;
              std::cout<<"           . 4 6 ."<<std::endl;
              std::cout<<"           . 123 ."<<std::endl;
              std::cout<<"           ......."<<std::endl;
              std::cin>>direction;          
          }while(!(direction==1 || direction==2 || direction==3 ||direction==4 ||
          direction==6 || direction==7 || direction==8 || direction==9));  
        }
        else if(gameGrid.d_mode == 2)
        {
          do 
          {
              std::cout<<"           ......."<<std::endl;
              std::cout<<"           .  8  ."<<std::endl;
              std::cout<<"           . 4 6 ."<<std::endl;
              std::cout<<"           .  2  ."<<std::endl;
              std::cout<<"           ......."<<std::endl;
              std::cin>>direction;          
          }while(!(direction==2 ||direction==4 || direction==6  || direction==8 ));
        }
        
        
 
        gameGrid.movePlayer(direction);
        std::cout<<"--------------------"<<std::endl;
        std::cout<<"The player moves...."<<std::endl;
        gameGrid.display();
        if(gameGrid.playerLife())
        {
             std::cout<<"The wildcats moves...."<<std::endl;
             gameGrid.moveAllWildact();
             gameGrid.display();      
        }
        else
        {
             std::cout<<"SCORE :    Number of rounds : "<<gameGrid.getPlayerLifeTime()<<"    Number of dead wilcats : "<<gameGrid.getDeadWildAnimalsNumber()<<std::endl<<std::endl;
             std::cout<<"The player is dead"<<std::endl;
             std::cout<<"----------------------------"<<std::endl;
             std::cout<<"--------- YOU LOSE ---------"<<std::endl;
             std::cout<<"----------------------------"<<std::endl;
             gameGrid.display(); 
        }
        
     }
     if(gameGrid.playerLife())
     {
       std::cout<<"SCORE :    Number of rounds : "<<gameGrid.getPlayerLifeTime()<<"    Number of dead wilcats : "<<gameGrid.getDeadWildAnimalsNumber()<<std::endl<<std::endl;
       std::cout<<"The wildcats are dead"<<std::endl;
       std::cout<<"---------------------------"<<std::endl;
       std::cout<<"--------- YOU WIN ---------"<<std::endl;
       std::cout<<"---------------------------"<<std::endl;
     }
     else
     {
         std::cout<<"SCORE :    Number of rounds : "<<gameGrid.getPlayerLifeTime()<<"    Number of dead wilcats : "<<gameGrid.getDeadWildAnimalsNumber()<<std::endl<<std::endl;
         std::cout<<"The player is dead"<<std::endl;
         std::cout<<"----------------------------"<<std::endl;
         std::cout<<"--------- YOU LOSE ---------"<<std::endl; 
         std::cout<<"----------------------------"<<std::endl;
     }
}