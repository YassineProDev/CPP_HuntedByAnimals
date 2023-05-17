#include "../headers/interface.h"
#include "../headers/grid.h"
#include "../headers/trap.h"
#include "../headers/rock.h"
#include "../headers/lion.h"
#include "../headers/cheetah.h"
#include "../headers/player.h"
#include "../headers/playerNormalLevel.h"
#include "../headers/playerDifficultLevel.h"


interface::interface()
{

}

void interface::displayGrid(const grid& gr) const
{
    std::vector<std::vector<char>> g;

    g.resize(gr.d_height);
    for (int i = 0 ; i < gr.d_height ; i++) 
      g[i].resize(gr.d_width);

    for(int i=0; i<gr.d_height; i++)
    {
        for(int j=0; j<gr.d_width; j++)
        {
            g[i][j] = '-';
        }
    }
    
    for(int i=0; i<gr.wildAnimalsList.size(); i++)
    {
        if(gr.wildAnimalsList[i]->getLife())
        {
            if(dynamic_cast<cheetah*>(gr.wildAnimalsList[i].get()))
            {
              g[gr.wildAnimalsList[i]->getPos().getX()][gr.wildAnimalsList[i]->getPos().getY()] = displayCheetah();
            }
            else
            {
              g[gr.wildAnimalsList[i]->getPos().getX()][gr.wildAnimalsList[i]->getPos().getY()] = displayLion();
            }
        }
    }
    
   
    for(int i=0; i<gr.gridElementList.size(); i++)
    {
        if(dynamic_cast<trap*>(gr.gridElementList[i].get()))
            g[gr.gridElementList[i]->getPos().getX()][gr.gridElementList[i]->getPos().getY()] = displayTrap();
        else
            g[gr.gridElementList[i]->getPos().getX()][gr.gridElementList[i]->getPos().getY()] = displayRock();
    }
    if(gr.Player[0]->getLife())
    {
        if(dynamic_cast<playerNormalLevel*>(gr.Player[0].get()))
          g[gr.getPosPlayer().getX()][gr.getPosPlayer().getY()]  = displayPlayerNormalLevel();
        else
           g[gr.getPosPlayer().getX()][gr.getPosPlayer().getY()]  = displayPlayerDifficultLevel();
    }
    for(int i=0; i<gr.d_height; i++)
    {
        for(int j=0; j<gr.d_width; j++)
        {
            std::cout<<g[i][j]; 
        }
        std::cout<<std::endl;
    }
}

char interface::displayCheetah() const
{
    return 'C';
}

char interface::displayLion() const
{
    return 'L';
}

char interface::displayTrap() const
{
    return 'T';
}

char interface::displayRock() const
{
    return 'R';
}

char interface::displayPlayerDifficultLevel() const
{
    return 'D';
}

char interface::displayPlayerNormalLevel() const
{
    return 'P';
}
