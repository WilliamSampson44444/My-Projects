/*
  William F. Sampson
  williamsampson44444@gmail.com
  wsampson
  Assignment 2: Heaps of Fun
  2/23/17
  Heap.cpp
  Function definitions for Heap class.
  Status: 1-in-a-million completed - untested.
 */

#include <sstream>
#include "Heap.h"

using namespace std;

Heap::Heap(int s){
  size = s;
  capacity = 2400000;
}

void Heap::buildHeap(){
  for(int i=size/2-1;i>=0;i--){
    heapify(i);
  }
}

int Heap::left(int i){
  if(2*i+1<size){
    return 2*i+1;
  }
  return -1;
}

int Heap::right(int i){
  if(2*i+2<size){
    return 2*i+2;
  }
  return -1;
}

void Heap::heapify(int i){
  int n = i;
  if(left(i) < i){n = left(i);}
  if(right(i) < i){n = right(i);}
  if(n != i){
    swap(i,n);
    heapify(n);
  }
}

bool Heap::insert(int key){
  if(size = capacity){return false;}//Bounds check?
  A[size] = key-1;
  size++;
  decreaseKey(size, key);
  return true;
}

void Heap::decreaseKey(int index, int key){
  //Bounds check?
  if(A[index] >= key){return;};
  A[index] = key;
  while(index > 0 && A[parent(index)] > A[index]){
    int temp = A[index];
    index = parent(index);
  }
}

int Heap::extractMin(){
  if (!size){//Sanitycheck, in case size = 0
    return 0;
  }
  int min = A[0];
  A[0] = A[size-1];
  size--;
  heapify(0);
  return min;
}

//99% sure will need debugging
int Heap::heapsort(){
  int* sorted = new int[size];
  int* temp = new int[size];
  for(int i = 0; i < size; i++){
    sorted[i] = A[i];
  }
  sorted = A;
  A = temp;
  int num;
  int tempSize = size;
  for(int i = size-1; i>0; i--){
    num = A[0];
    A[0] = A[i];
    A[i] = num;
    tempSize--;
    heapify(0);
  }
  temp = sorted;
  sorted = A;
  A = temp;
  return *sorted;
}

string Heap::toString(){
  stringstream ss;
  ss >> size;
  string str = "heap size " + ss.str() + ": ";
  for(int i = 0; i < size; i++){
    if(i>0){
      str+=", ";
    }
    str +=A[i];
  }
  return str;
}

Heap::~Heap(){

}
