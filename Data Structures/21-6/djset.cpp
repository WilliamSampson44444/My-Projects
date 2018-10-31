/*
  William F. Sampson
  williamsampson44444@gmail.com
  wsampson
  Assignment 6: Amazing Sets
  4/12/17
  djset.cpp
  djset class definitions file for Amazing Sets program.
  Status: Complete
*/

#include <iostream>
#include <cstdlib>
#include "djset.h"

using namespace std;

djset::djset(int side){
  if(side < 3){
    cerr << "Reminder: The minimum side length of a maze is 3." << endl;
    exit(0);
  }
  size = side * side;
  length = side;
  rank = new int[size];
  parent = new int[size];
  for(int i = 0; i < size; i++){
    parent[i] = i;
    rank[i] = 0;
  }
}

int djset::FindSet(int x){
  if(0 <= x && x < size){
    if(x != parent[x]){
      parent[x] = FindSet(parent[x]);
    }
    return parent[x];
  }else{
    cerr << "Out of bounds attempted by Find-Set" << endl;
    exit(-1);
  }
}

bool djset::Union(int x, int y){
  if(0 <= x && x < size && 0 <= y && y < size){
    Link(FindSet(x), FindSet(y));
    return true;
  }else{
    return false;
  }
}

void djset::Link(int x, int y){
  if(x==y)return;
  if(rank[x] > rank[y]){
    parent[y] = x;
  }else{
    parent[x] = y;
    if(rank[x] == rank[y]){
      rank[y]++;
    }
  }
}

bool djset::SameComponent(int x, int y){
  if((x >= 0 && y >= 0) && (x < size && y < size)){
    return (FindSet(x) == FindSet(y));
  }else{
    return false;
  }
}
