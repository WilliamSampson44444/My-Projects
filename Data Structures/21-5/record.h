/*
  William F. Sampson
  williamsampson44444@gmail.com
  wsampson
  Assignment 5: Hash... Table
  3/30/17
  record.h
  Header file for record class in Hash Tables assignment.
  Status: Complete
*/

using namespace std;

#ifndef RECORD_H
#define RECORD_H

class record{
 public:
  record(int key, string input){stuff = input; ID = key;};
  int getID(){return ID;};
  string getStuff(){return stuff;};
  record *clone(){return new record(ID, stuff);};
 private:
  string stuff;
  int ID;
};
#endif
