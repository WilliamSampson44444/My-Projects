/*
  William F. Sampson
  williamsampson44444@gmail.com
  wsampson
  Assignment 6: Amazing Sets
  4/06/17
  main.cpp
  Main function for Amazing Sets program.
  Status: Complete
  Function: given an int, creates a random maze with that height and width.
*/

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "maze.h"

using namespace std;

int main(int argc, char** argv){
  srand(time(NULL));
  int length = atoi(argv[1]);
  maze m(length);
  m.mazeify();
  m.printMaze();
  return 0;
}
