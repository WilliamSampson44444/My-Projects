/*
  William F. Sampson
  williamsampson44444@gmail.com
  wsampson
  Assignment 5: Hash... Table
  3/30/17
  hashTable.cpp
  Function definitions for hashTable class in Hash Tables assignment.
  Status: Complete
 */

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <fstream>
#include "record.h"
#include "hashTable.h"

using namespace std;

hashTable::hashTable(){
  C = (sqrt(5)-1)/2;
  size=0;
  for(int i = 0; i < 100; i++){
    vector<record*> temp;
    data.push_back(temp);
  }
}
hashTable::hashTable(int m){
  C = (sqrt(5)-1)/2;
  size=0;
  for(int i = 0; i < m; i++){
    vector<record*> temp;
    data.push_back(temp);
  }
}

hashTable::~hashTable(){//This is my pathetic attempt at avoiding memory leaks
  for(int i = 0; i < data.size(); i++){
    for(int j = 0; j < data[i].size(); j++){
      delete[] data[i][j];
    }
  }
}

void hashTable::insert(string input){
  int key;
  key = stoi(input, NULL, 10);
  record* rec = new record(key, input);
  int place = hash(key);
  data[place].push_back(rec);
}

string hashTable::remove(int key){
  int location = hash(key);
  string result = "";
  if(data[location].size() > 0){
    for(int i = data[location].size()-1; i >= 0; i--){
      if(key == data[location][i]->getID()){
	result = data[location][i]->getStuff();
        data[location].erase(data[location].begin() + i);
	i = -1;
      }
    }
  }
  return result;
}

string hashTable::search(int key){
  int location = hash(key);
  if(data[location].size() > 0){
    for(int i = data[location].size()-1; i >= 0; i--){
      if(key == data[location][i]->getID()){
	return data[location][i]->getStuff();
      }
    }
  }else{
    return "";
  }
}

void hashTable::getAll(){
  string filename;
  getline(cin, filename);
  ofstream fout;
  fout.open(filename.c_str());
  if(fout.fail()){
    cerr << "Output file failed to open.\n";
    exit(-1);
  }
  for(int i = 0; i < data.size(); i++){
    for(int j = 0; j < data[i].size(); j++){
      fout << data[i][j]->getStuff() << endl;
    }
  }
  fout.close();
}

int hashTable::hash(int key){
  return (int)(178000*(C*key-(int)(C*key)));
}
