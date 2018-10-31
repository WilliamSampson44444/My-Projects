/*
  William F. Sampson
  williamsampson44444@gmail.com
  wsampson
  Assignment 7: Binary Search tree
  4/27/17
  bstree.h
  Binary Search Tree class header for Binary Search Tree program.
  NOTE: All function definitions assume that each key is unique. Unpredictable
  bugs may occur with the insertion of non-unique keys.
  Status: Complete
*/

#include "bsnode.h"

#ifndef BSTREE_H
#define BSTREE_H

class bstree{
 public:
  bstree(){root = nullptr;};//default constructor
  void insert(int key);//Insert node with data=key at appropriate spot
  bool find(int key){return search(root, key);};//Wrapper for search
  bool remove(int key);//Remove node with data=key at appropriate spot
  void getMin();//Wrapper for min
  void getMax();//Wrapper for max
  void DoInOrder(){inOrder(root);};//Wrapper for inOrder
  void DoPreOrder(){preOrder(root);};//Wrapper for preOrder
  void DoPostOrder(){postOrder(root);};//Wrapper for postOrder
  void getCessor(int x, char y);/*Takes int, finds node with x in bst, finds 
				  s-uccessor or p-redecessor, prints data to 
				  stdout */
 private:
  //pvt functions
  void inOrder(bsnode* x);//Prints data of each node in tree, in order.
  void preOrder(bsnode* x);//Prints data of each node in tree, preOrder style.
  void postOrder(bsnode* x);//Prints data of each node in tree, postOrder style
  bsnode* search(bsnode* x, int key);//Searches for node with key, returns ptr
  bsnode* predecessor(bsnode* x);//Returns ptr to predecessor of node x
  bsnode* successor(bsnode* x);//Returns ptr to successor of node x
  bsnode* min(bsnode* x);//Non-recursive, finds node with minimum data under x
  bsnode* max(bsnode* x);//Non-recursive, finds node with maximum data under x
  //pvt data
  bsnode* root;//Root of tree
};
#endif
