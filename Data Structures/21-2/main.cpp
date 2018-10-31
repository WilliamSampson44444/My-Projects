/*
  William F. Sampson
  williamsampson44444@gmail.com
  wsampson
  Assignment 2: MinHeaps of Fun
  2/23/17
  main.cpp
  Main function of Assignment 2: Heaps of Fun
  Status: Probably Complete, Untested
 */

#include <iostream>
#include <fstream>
#include "Heap.h"

using namespace std;

int main(){
  Heap foo(0);
  
  int operation;
  int* A;
  while (operation >= -2){
    cin >> operation;
    if(operation > 0){
      foo.insert(operation);
    }else if(operation == 0){
      cout << foo.toString() << endl;
    }else if(operation == -1){
      foo.extractMin();
    }else if(operation == -2){
      int A = foo.heapsort();
      int size = foo.getSize();
      for(int i = 0; i < size; i++){
	
      }
    }
  }
  return 0;
}
