#include "../headers/grid.h"
#include "../headers/trap.h"
#include "../headers/rock.h"
#include "../headers/lion.h"
#include "../headers/cheetah.h"
#include "../headers/player.h"
#include "../headers/playerNormalLevel.h"
#include "../headers/playerDifficultLevel.h"
#include "../headers/wildAnimal.h"
#include "../headers/interface.h"


grid::grid(int choice, std::string name) : d_choice{choice}, nameFile{name},  deadWildAnimalsNumber{0}, playerLifeTime{0}
{
    if(d_choice == 1)
    {
        gridByDefault();
    }
    else
    {
        gridImport(nameFile);
    }
}

void grid::gridByDefault()
{
    int choice;
    std::cout<<"-------- SELECT MODE -----------"<<std::endl;
    std::cout<<"1 - Normal mode"<<std::endl;
    std::cout<<"2 - Difficult mode"<<std::endl;
    std::cout<<"--------------------------------"<<std::endl;
    std::cin>>choice;
    
    wildAnimalsList.push_back(std::make_unique<lion>(position(1, 1)));
    wildAnimalsList.push_back(std::make_unique<cheetah>(position(2, 5)));
    wildAnimalsList.push_back(std::make_unique<cheetah>(position(6, 3)));
    wildAnimalsList.push_back(std::make_unique<lion>(position(7, 5)));


    gridElementList.push_back(std::make_unique<trap>(position(2,1)));
    gridElementList.push_back(std::make_unique<trap>(position(3,1)));
    gridElementList.push_back(std::make_unique<trap>(position(4,1)));
    gridElementList.push_back(std::make_unique<trap>(position(6,2)));

    gridElementList.push_back(std::make_unique<rock>(position(4,4)));
    if(choice == 1)
    {
        Player.push_back(std::make_unique<playerNormalLevel>(position(5,1)));
        d_mode = 1;
    }
    else if(choice == 2)
    {
        Player.push_back(std::make_unique<playerDifficultLevel>(position(5,1)));
        d_mode = 2;
    }
      

    d_height = 8;
    d_width = 8;
}

void grid::gridImport(std::string nameFile)
{
   std::ifstream ifs(nameFile);
    if (!ifs.is_open()) {
       std::cout << "Error opening file." << std::endl;
       return;
   }
   int height,width;
   char c;
   ifs>>c>>height>>c>>width>>c;

   d_height = height;
   d_width = width;

   int line=0, column=0;

    while(!ifs.eof() && line<height && column < width)
    {
        ifs>>c;
        if(c=='L')
        {
            wildAnimalsList.push_back(std::make_unique<lion>(position(line,column)));
        }
        else if(c=='C')
        {
           wildAnimalsList.push_back(std::make_unique<cheetah>(position(line,column)));
        }
        else if(c=='R')
        {
             gridElementList.push_back(std::make_unique<rock>(position(line,column)));
        }
        else if(c=='T')
        {
             gridElementList.push_back(std::make_unique<trap>(position(line,column)));
        }
        else if(c=='P')
        {
            d_mode = 1;
            Player.push_back(std::make_unique<playerNormalLevel>(position(line,column)));
        }
        else if(c=='D')
        {
            d_mode = 2;
           Player.push_back(std::make_unique<playerDifficultLevel>(position(line,column)));
        }

        column++;
        if(column==width)
        {
            column=0;
            line+=1;
        }
    }
}



int grid::gridElementAtPosition(position p) const
{
    for(int i=0; i<gridElementList.size(); i++)
    {
        if(gridElementList[i]->getPos()==p)
        {
            if(dynamic_cast<trap*>(gridElementList[i].get()) != nullptr)
            {
                return 1;
            }
            else if(dynamic_cast<rock*>(gridElementList[i].get()) != nullptr)
            {
                return 2;
            }
        }
    }
    return 0;
}

int grid::wildcatAtPosition(position p) const
{
    for(int i=0; i<wildAnimalsList.size(); i++)
    {
        if(wildAnimalsList[i]->getLife() == true && wildAnimalsList[i]->getPos()==p)
        {
            if(dynamic_cast<lion*>(wildAnimalsList[i].get()) != nullptr)
            {
                return 3;
            }
            else if(dynamic_cast<cheetah*>(wildAnimalsList[i].get()) != nullptr)
            {
                return 4;
            }
        }
    }
    return 0;
}

int grid::elementAtPosition(position p) const
{
    int i = wildcatAtPosition(p);
    int j = gridElementAtPosition(p);
    if(i != 0)
    {
        return i;
    }
    else if(j != 0)
    {
        return j;
    }
    else if (p==getPosPlayer())
    {
        return 5;
    }
    else
    {
        return 0;
    }
}

position grid::getPosPlayer() const
{
    return Player[0]->getPos();
}


void grid::movePlayer(int direction)
{
    if(Player[0]->getLife() == false)
    {
        return;
    }
    else
    {
        position newPos = Player[0]->newPos(direction);
        if(validPosition(newPos))
        {
            int i = elementAtPosition(newPos);
            movePalyerOn(i,newPos);
        }
    }
}



void grid::movePalyerOn(int situation,position newPos)
{
    if(situation == 0)
    {
        Player[0]->setPosition(newPos);
        ++playerLifeTime;
    }
    else if(situation == 1 || situation == 3 || situation == 4)
    {
        Player[0]->kill();
    }
}


void grid::moveWildcat(int i)
{
    if(wildAnimalsList[i]->getLife() == false)
    {
        return;
    }
    else
    {
        position posJoueur = getPosPlayer();
        position newPos = wildAnimalsList[i]->newPos(posJoueur,*this);
        if(validPosition(newPos))
        {
           int s = elementAtPosition(newPos);
           moveWildcatOn(s, newPos,i);
        }
    }
}

void grid::moveAllWildact()
{
    for (unsigned i=0; i < wildAnimalsList.size(); ++i)
        moveWildcat(i);
}

int  grid::caseWildcatAtPosition(position p)
{
    for(int i=0; i<wildAnimalsList.size(); i++)
    {
        if(wildAnimalsList[i]->getLife() == true && wildAnimalsList[i]->getPos()==p)
        {
            return i;
        }
    }
    return -1;
}

void grid::moveWildcatOn(int situation,position newPos, int i)
{
    if(situation == 0)
    {
        wildAnimalsList[i]->setPosition(newPos);
    }
    else if(situation == 1)
    {
       wildAnimalsList[i]->kill();
        deadWildAnimalsNumber++;
    }
    else if(situation == 5)
    {
       Player[0]->kill();
       wildAnimalsList[i]->setPosition(newPos);
    }
    else if(dynamic_cast<cheetah*>(wildAnimalsList[i].get()) != nullptr && situation == 3 || 
            dynamic_cast<lion*>(wildAnimalsList[i].get()) != nullptr && situation == 4)
    {
        int j = caseWildcatAtPosition(newPos);
        wildAnimalsList[i]->setPosition(newPos);
        wildAnimalsList[j]->kill();
        deadWildAnimalsNumber++;
    }
   
}



int grid::getDeadWildAnimalsNumber() const
{
  return deadWildAnimalsNumber;
}

int grid::getPlayerLifeTime() const
{
   return playerLifeTime; 
}

bool grid::gameOver()
{
    if(playerLife() == false || wildcatLife() == false)
       return true;
    else 
       return false;
}

bool grid::playerLife()
{
    return Player[0]->getLife();
}

bool grid::wildcatLife()
{
    int i=0;
    while(i < wildAnimalsList.size() && wildAnimalsList[i]->getLife() == false)
    {
      i++;
    }
    return i!=wildAnimalsList.size();
    
}

void grid::display()
{
    interface f{};
    f.displayGrid(*this);
}

bool grid::validPosition(position p)
{
    if(p.getX() <0 || p.getX()>d_height-1 || p.getY() <0 || p.getY()>d_width-1)
    {
        return false;
    }
    else
    {
        return true;
    }
}
