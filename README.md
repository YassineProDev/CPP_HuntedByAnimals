<div align="center">
  
# Installation
  
</div>

## Installation of the development environment
  
 - Install Visual Studio Code.
 - In Visual Studio Code click on the "Extensions" icon in the left-hand menu (or press "Ctrl+Shift+X") and install the extension : "C/C++".
 - Next, you need to install a compiler. Go to the Oracle JDK download page: https://www.msys2.org/.
   and follow the differents steps.
 - To install the full compiler toolchain open the MYSY2 terminal and type : pacman -S --needed base-devel mingw-w64-x86_64-toolchain
 
 - Add the path to your Mingw-w64 bin folder to the Windows PATH environment variable by using the following steps:
     - In the Windows search bar, search Edit environment.
     - Choose the Path variable in your User variables and then select Edit.
     - Select New and add the Mingw-w64 destination folder path, and type the path : C:\msys64\mingw64\bin
     - Select OK to save the updated PATH. You will need to reopen any console windows for the new PATH location to be available.

## Opening and compilation of the project

- Then open the project in Visual Studio Code by opening the file "CPP_PlayerHuntedByWildAnimals-main".
- In the Visual Studio Code terminal go in the current directory.
<div align="center">
  
![11](https://github.com/YassineProDev/CPP_PlayerHuntedByWildAnimals/assets/120946916/695ff667-7b17-4d6a-875d-38683b1126a0)
  
</div>

- Then compile the project by writing  : g++ src/*.cpp -I headers -o main.exe ; ./main.exe

<div align="center"> 
  
![0](https://github.com/YassineProDev/CPP_PlayerHuntedByWildAnimals/assets/120946916/fa9fd1d4-37fe-4e72-9658-93861132f943)
  
  
# Presentation


## Select the your grid
  
![1](https://github.com/YassineProDev/CPP_PlayerHuntedByWildAnimals/assets/120946916/66016047-69ba-454b-98b6-ec7d82fc1fe5)

## Select the mode
  
![222](https://github.com/YassineProDev/CPP_PlayerHuntedByWildAnimals/assets/120946916/5dcac32a-0813-4d1d-969c-0b126854b22e)

## The grid is then displayed. Choose your direction.
  
![3](https://github.com/YassineProDev/CPP_PlayerHuntedByWildAnimals/assets/120946916/5c5f4d3e-1ecf-48f1-917b-85bf15c66a43)

## The player moves on the grid. Then all the wild animals move towards the player.
 
![4](https://github.com/YassineProDev/CPP_PlayerHuntedByWildAnimals/assets/120946916/451cb92d-7e9a-48ba-9417-8913220191a3)
  
## Win the game by making the wild animals fall into the traps or by making them eat each other.
 
![5](https://github.com/YassineProDev/CPP_PlayerHuntedByWildAnimals/assets/120946916/40ec13a6-b1db-41b6-b39c-889ff93936a2)
  
</div>

  
  
  
