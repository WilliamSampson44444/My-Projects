/*
  William F. Sampson
  williamsampson44444@gmail.com
  wsampson
  Assignment 2: MinHeaps of Fun
  2/23/17
  Heap.h
  Header file of Heap class: 0-based, minimum.
  Status: Potentially complete, Untested
 */

#ifndef HEAP_H
#define HEAP_H

//Heap class: Turns arrays into 0-based minHeaps, manipulates those Heaps.
class Heap{
 public:
  Heap(int);//Constructor
  ~Heap();
  bool insert(int key);//Inserts a value into a valid position on the Heap
  void decreaseKey(int index, int key);//Helper for insert()
  int extractMin();//Extracts minimum value, resorts heap.
  int heapsort();//Takes heap, makes deep copy, sorts copy, returns copy.
  std::string toString();//Self-Explanatory
  int minimum(){if(size){return A[0];}else{return 0;};};
  bool isEmpty(){return size==0;};
  bool isFull(){return size==capacity;};
  int getSize(){return size;};
 private:
  void heapify(int i);//Heapifies the heap - self-calling
  void buildHeap();//Self-Explanatory
  int left(int i);//Rtrn left child i
  int right(int i);//Rtrn right child i
  int parent(int i){if(i>0){return (i-1)/2;}else{return 0;}};//Rtrn prnt index
  int size;
  int* A;
  int capacity;
};
#endif
