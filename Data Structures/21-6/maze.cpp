/*
  William F. Sampson
  williamsampson44444@gmail.com
  wsampson
  Assignment 6: Amazing Sets
  4/12/17
  maze.cpp
  maze class definitions file for Amazing Sets program.
  Status: Complete
*/

#include <iostream>
#include <cstdlib>
#include <random>
#include <vector>
#include "djset.h"
#include "maze.h"

using namespace std;

maze::maze(int length){//done
  side = length;//Important not to confuse side with size
  size = side * side;
  dj = new djset(length);
  walls = new int[size];
  walls[0] = 11;
  walls[size-1] = 14;
  for(int i = 1; i < size-1; i++){
    walls[i] = 15;
  }
}

void maze::mazeify(){
  vector<int> order;
  while(!dj->SameComponent(0, size-1)){
    for(int i = 0; i < size; i++){//Refer to comment block below breaks 4 info
      if(rand() % 2 == 0){
	breakLeft(i);
      }else {
	breakDown(i);
      }
    }
    order.clear();
  }
}

/*
  In mazeify(), always tries to break left first. If left can't be broken, 
  tries to break down, then right, then up. Only ever breaks 1 pair of walls 
  per pass, if any. areAdjacent helper function does bounds checking.
 */
void maze::breakLeft(int index){
  if(areAdjacent(index, index-1) && !dj->SameComponent(index, index-1)){
    if(dj->Union(index, index-1)){
      walls[index] -= 4;
      walls[index-1] -= 1;
    }
  }else{
    breakRight(index);
  }
}

void maze::breakDown(int index){
  if(areAdjacent(index, index+side) && !dj->SameComponent(index, index+side)){
    if(dj->Union(index, index+side)){
      walls[index] -= 2;
      walls[index+side] -= 8;
    }
  }else{
    breakUp(index);
  }
}

void maze::breakRight(int index){
  if(areAdjacent(index, index+1) && !dj->SameComponent(index, index+1)){
    if(dj->Union(index, index+1)){
      walls[index] -= 1;
      walls[index+1] -= 4;
    }
  }
}

void maze::breakUp(int index){
  if(areAdjacent(index, index-side) && !dj->SameComponent(index, index-side)){
    if(dj->Union(index, index-side)){
      walls[index] -= 8;
      walls[index-side] -= 2;
    }
  }
}

bool maze::areAdjacent(int x, int y){
  if(x < 0 || y < 0 || x >= size || y >= size){//OOB check
    return false;
  }
  if(x % side == 0 && y % side == side-1){//checking side overlap
    return false;
  }else if(y % side == 0 && x % side == side-1){
    return false;
  }
  return true;
}

void maze::printMaze(){
  for(int i = 0; i < size; i++){
    cout << hex << walls[i];
    if(i % side == side-1){
      cout << endl;
    }
  }
}
