#include "../headers/game.h"
#include "../headers/menu.h"

menu::menu()
{
    start();
}

int menu::choice()
{
    int choice;
    do 
    {
      std::cout<<"-------- PLAYER HUNDED BY WILDCATS --------"<<std::endl;
      std::cout<<"1 - Play on the default field"<<std::endl;
      std::cout<<"2 - Import terrain from file"<<std::endl;
      std::cout<<"-------------------------------------------"<<std::endl;
      std::cin>>choice;
    }while(!(choice==1 || choice==2));
    return choice;
}

std::string menu::nameFile()
{

   std::string name;
   std::cout<<"-----------------------------------------------------------------------------------"<<std::endl;
   std::cout<<"Instruction"<<std::endl;
   std::cout<<"Your file must be in the folder 'files'. You will find in this folder a file named"<<std::endl;
   std::cout<<"'example.txt' serving as an example of the structure of a file containing a grid."<<std::endl;
   std::cout<<"-----------------------------------------------------------------------------------"<<std::endl;
   std::cout<<"Enter the file name"<<std::endl;
   std::cin>>name;

   std::string path = "files/" + name;
   return path;
}

void menu::start()
{
    int c = choice();
    if(c == 1)
    {
       std::string name = " ";
       game g{c,name};
    }
    else if(c==2)
    {
       std::string name = nameFile();
       game g{c,name};
    }
}