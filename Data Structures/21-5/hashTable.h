/*
  William F. Sampson
  williamsampson44444@gmail.com
  wsampson
  Assignment 5: Hash... Table
  3/30/17
  hashTable.h
  Header file for hashTable class in Hash Tables assignment.
  Status: Complete
 */

#include <string>
#include <vector>
#include "record.h"
using namespace std;

#ifndef HASHTABLE_H
#define HASHTABLE_H

class hashTable{
 public:
  hashTable();//default constructor
  hashTable(int m);//constructor
  ~hashTable();//destructor
  void insert(string input);//insert copy of record
  string remove(int key);//delete a record
  string search(int key); //return a copy of a record w/ given key (if exists)
  void getAll();
 private:
  int hash(int key);//hash value for key  
  vector<vector<record*> > data;//data container
  int size;//how many elements there are in the hashTable
  double C;//Hashing constant
};
#endif
