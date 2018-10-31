/*
  William F. Sampson
  williamsampson44444@gmail.com
  wsampson
  Assignment 1: Linked List
  Last Modified: 1/31/17
  main.cpp
  Main function for Linked List Assignment.
  Complete (Probably): Program should function as specified by the guidelines
  on the website. Admittedly, there is no "Stack" class, mostly because I have 
  no idea how to do inheritance. I don't even remember discussing this in CS19.
 */

#include <iostream>
#include <string>
#include "List.h"

using namespace std;

int main(){
  List lmao;

  string input;
  
  while(cin >> input){
    lmao.push(input);
  }
  lmao.print();
}
