/*
  William F. Sampson
  williamsampson44444@gmail.com
  wsampson
  Assignment 6: Amazing Sets
  4/06/17
  djset.h
  djset class header file for Amazing Sets program.
  Status: Complete
*/

#ifndef DJSET_H
#define DJSET_H

class djset{
 public:
  djset(){};//default constructor, to get around weird compiler stuff
  djset(int side);//constructor
  bool Union(int x, int y);//Takes 2 indexes, bounds checks, Links
  int FindSet(int x);//Finds the final parent of an index
  bool SameComponent(int x, int y);/*Checks if indexes x and y are 
						in same set*/
 private:
  //pvt functions
  void Link(int x, int y);//Takes 2 indexes, puts them in the same set
  //pvt variables
  int length;//Length of one side of the maze
  int size;//Contains the size of the set - thus the sizes of rank and parent
  int* rank;//array containing the rank of each index
  int* parent;//array containing the parent of each index
};
#endif
