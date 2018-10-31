/*
  William F. Sampson
  williamsampson44444@gmail.com
  wsampson
  Assignment 5: Hash... Table
  3/30/17
  main.cpp
  Main function for HashTable program.
  Status: Complete
 */

#include <iostream>
#include <cstdlib>
#include <fstream>
#include "record.h"
#include "hashTable.h"

using namespace std;

const int sizeOfFoo = 178000;

int main(){
  hashTable *foo = new hashTable(sizeOfFoo);
  char choicestr;
  string filename;
  string input = "";
  string temp;
  int key;
  string results;
  while(choicestr != '7'){
    cout << "(1)load (2)insert (3)delete (4)search (5)clear (6)save (7)quit"
	 << " -- Your choice? ";
    getline(cin, temp);
    choicestr = temp[0];
    if(choicestr == '1'){//load - 1
      cout << "Read hash table - filename? ";
      getline(cin, filename);
      ifstream fin;
      fin.open(filename.c_str());
      if(fin.fail()){
	cerr << "Input file failed to open.\n";
	exit(-1);
      }
      while(getline(fin, input)){
	foo->insert(input);
      }
      fin.close();

    }else if(choicestr == '2'){//insert - 2
      cout << "input new record: ";
      getline(cin, input);
      foo->insert(input);

    }else if(choicestr == '3'){//delete - 3
      cout << "delete record - key? ";
      getline(cin,temp);
      key = stoi(temp, NULL, 10);
      results = foo->remove(key);
      if(results.size() == 0){
	cout << endl << "Delete not found: " << key << endl;
      }else{
	cout << endl << "Delete: " << results << endl;
      }

    }else if(choicestr == '4'){//search - 4
      cout << "search for record - key? ";
      getline(cin, temp);
      key = stoi(temp, NULL, 10);
      results = foo->search(key);
      if(results.size() == 0){
	cout << "Search not found: " << key << endl;
      }else{
	cout << endl << "Found: " << results << endl;
      }

    }else if(choicestr == '5'){//clear - 5
      cout << "Clearing hash table.\n";
      delete foo;
      hashTable *foo = new hashTable(sizeOfFoo);

    }else if(choicestr == '6'){//save - 6
      cout << "Write hash table - filename? ";
      foo->getAll();
    }
  }
  return 0;
}
