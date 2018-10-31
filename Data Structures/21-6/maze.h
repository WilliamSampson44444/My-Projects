/*
  William F. Sampson
  williamsampson44444@gmail.com
  wsampson
  Assignment 6: Amazing Sets
  4/12/17
  maze.h
  maze class header file for Amazing Sets program.
  Status: Complete
*/

#include "djset.h"

#ifndef MAZE_H
#define MAZE_H

class maze{
 public:
  maze(int length);//Constructor
  void mazeify();//Main doer-of-stuff function
  void printMaze();//Prints maze to stdout
 private:
  void breakLeft(int index);//Breaks left wall of index (w/ boundscheck)
  void breakRight(int index);//Breaks right wall of index (w/ boundscheck)
  void breakDown(int index);//Breaks lower wall of index (w/ boundscheck)
  void breakUp(int index);//Breaks lower wall of index (w/ boundscheck)
  bool areAdjacent(int x, int y);//Helper for breaks, checks for adjacency.
  djset* dj;
  int* walls;//int array, holds wall status of each square in maze
  int side;//Length of one side of the maze
  int size;//Total number of elements in maze
};
#endif
