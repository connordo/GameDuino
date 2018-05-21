#include <iostream>
#include <cstdlib>
#include <ctime>

#define MAZE_X_SIZE 21
#define MAZE_Y_SIZE 10

using namespace std;

void printMaze(int array[MAZE_X_SIZE][MAZE_Y_SIZE]){
  for(int i = 0; i < MAZE_Y_SIZE; i++){
    for(int j = 0; j < MAZE_X_SIZE; j++){
      if(array[j][i] == 0)
      cout << "0 ";
      else
      cout << ". ";
    }
    cout << endl;
  }
  cout << "\n\n\n";
}

void mazeGenerator(int maze[MAZE_X_SIZE][MAZE_Y_SIZE], int x, int y){
  maze[x][y] = 1;
  int optionsLeft = 4;
  while(optionsLeft > 0){
    //Get the available options
    int options[4] = {0};
    if(y - 1 >= 0 && maze[x][y - 1] == 0){
      options[0] = 1;
    }
    if(x + 1 < MAZE_X_SIZE && maze[x + 1][y] == 0){
      options[1] = 2;
    }
    if(y + 1 < MAZE_Y_SIZE && maze[x][y + 1] == 0){
      options[2] = 3;
    }
    if(x - 1 >= 0 && maze[x - 1][y] == 0){
      options[3] = 4;
    }
    optionsLeft = 0;
    for(int i = 0; i < 4; i++){
      if(options[i]!=0){
        optionsLeft++;
      }
    }

    ////////////////////
    cout << "options array:" << endl;
    for(int i = 0; i < 4; i++){
      cout << options[i] << " ";
    }
    cout << endl;
    ////////////////////

    //randomly select one of them
    int rando = rand() % 4;
    if(optionsLeft > 0){
      while(options[rando] == 0){
        rando = rand() % 4;
      }
    }
    cout << "rando: " << rando << endl;
    printMaze(maze);

    switch(options[rando]){
      case 1:
      mazeGenerator(maze, x, y - 1);
      break;
      case 2:
      mazeGenerator(maze, x + 1, y);
      break;
      case 3:
      mazeGenerator(maze, x, y + 1);
      break;
      case 4:
      mazeGenerator(maze, x - 1, y);
      break;
      default:
      break;
    }
    optionsLeft--;
    cout << "options Left: " << optionsLeft << endl;
  }
}

int main(){
  srand(time(0));
  cout << "Welcome to my maze tester!" << endl;
  int maze[MAZE_X_SIZE][MAZE_Y_SIZE] = {0};
  mazeGenerator(maze, 0, 0);
}
