/*
  William F. Sampson
  williamsampson44444@gmail.com
  wsampson
  Assignment 7: Binary Search Tree
  4/25/17
  bsnode.h
  Binary Search Node class header file for Binary Search Tree program.
  Status: Complete
*/

#ifndef BSNODE_H
#define BSNODE_H

class bsnode{
 public:
  bsnode(int num){data = num; parent = nullptr; left = nullptr; 
    right = nullptr;};//Constructor
  void setData(int num){data = num;};//Basic set wrappers
  void setParent(bsnode* num){parent = num;};
  void setLeft(bsnode* num){left = num;};
  void setRight(bsnode* num){right = num;};
  int getData(){return data;};//Basic get wrappers
  bsnode* getParent(){return parent;};
  bsnode* getLeft(){return left;};
  bsnode* getRight(){return right;};
 private:
  int data;
  bsnode* parent;
  bsnode* left;
  bsnode* right;
};
#endif
