/*
  William F. Sampson
  williamsampson44444@gmail.com
  wsampson
  Assignment 1: Linked List
  2/2/17
  List.cpp
  Definitions for functions in List class.
  Finished, Line 21 does not compile.
 */
#include <string>
#include <iostream>
#include "List.h"

using namespace std;

void List::print(){
  LinkNode *temp = first;
  string newStr = "";
  while(temp){
    newStr = temp->data; 
    /*Spits out some error about trying to convert from a string to a char
     despite both variables having been defined as strings.*/
    cout << newStr << endl;
    temp = temp->next;
  }
}

void List::push(string newData){
  LinkNode *temp = new LinkNode();
  temp->data = newData;
  temp->next = first;
  first = temp;
}
