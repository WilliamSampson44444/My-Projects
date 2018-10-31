/*
  William F. Sampson
  williamsampson44444@gmail.com
  wsampson
  Assignment 1: Linked List
  1/31/17
  List.h
  Header file for List class.
  Finished (Probably)
 */

#ifndef LIST_H
#define LIST_H
#include <string>
#include "LinkNode.h"

using namespace std;

/*
  Linked List class.
 */
class List{
 public:
  List(){first = NULL;}//Contructor
  void print();//Prints all entries in List, separated by newlines
  void push(string newData);//Adds node with data to front of List.
  //pop();//Removes node from front of List.
 private:
  LinkNode *first;//Pointer to first item in the list.
};

#endif
