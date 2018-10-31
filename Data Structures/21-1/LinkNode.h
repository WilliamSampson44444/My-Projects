/*
  William F. Sampson
  williamsampson44444@gmail.com
  wsampson
  Assignment 1: Linked List
  1/31/17
  LinkNode.h
  Header file for LinkNode class.
  Finished (Probably)
 */

#ifndef LINKNODE_H
#define LINKNODE_H
#include <string>

using namespace std;

class LinkNode{
  friend class List;
 public:
  LinkNode(){next = 0; data = "";}
  //~LinkNode(){if(data != ""){delete data; data = "";}}
 private:
  LinkNode *next;
  string data;
};

#endif
