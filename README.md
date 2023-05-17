<div align="center">
  
# Installation
  
</div>

## Installation of the development environment
  
 - Install Visual Studio Code.
 - In Visual Studio Code click on the "Extensions" icon in the left-hand menu (or press "Ctrl+Shift+X") and install the extension : "C/C++".
 - Next, you need to install a compiler. Go to the MYSYS2 download page: https://www.msys2.org/.
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
- Then compile the project by writing  :
```bash
g++ src/*.cpp -I headers -o main.exe ; ./main.exe
```
<div align="center"> 
  
  
# Presentation

## Select the your grid and the game mode
  
![1](https://github.com/YassineProDev/CPP_PlayerHuntedByWildAnimals/assets/120946916/f6de0fe4-47ff-4add-9a98-250a5fc3252b)

## The grid is then displayed. Choose your direction.
  
![2](https://github.com/YassineProDev/CPP_PlayerHuntedByWildAnimals/assets/120946916/060c9858-3935-484f-a077-2f455bdb62b3)

## The player moves on the grid. Then all the wild animals move towards the player.
  
![3](https://github.com/YassineProDev/CPP_PlayerHuntedByWildAnimals/assets/120946916/312afb21-1e11-44e5-93d8-15ee6fa61c8c)
  
## Win the game by making the wild animals fall into the traps or by making them eat each other.
  
![4](https://github.com/YassineProDev/CPP_PlayerHuntedByWildAnimals/assets/120946916/6d534921-3962-4af4-acd1-3225ed1997d8)

 
</div>

  
  
  
