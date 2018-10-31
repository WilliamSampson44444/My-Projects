/*
  William F. Sampson
  williamsampson44444@gmail.com
  wsampson
  Assignment 4: Racket Sort
  Last Modified 3/9/17
  main.cpp
  Main program file for Racket (Radix + Bucket) Sort assignment
  Status: Complete - COMPILED SECOND TRY BAYBEE
 */

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

const int digits = 9;//Number of digits in Assignemnent ver. of Racket Sort

void RacketSort(vector<int>& foo);

int main(){
  int input;
  vector<int> foo;
  while(cin >> input){//STDIN
    foo.push_back(input);
  }
  RacketSort(foo);//Sorting
  for(int i = 0; i < foo.size(); i++){//STDOUT
    cout << setfill('0') << setw(digits) << foo[i] << endl;
  }
  return 0;
}

void RacketSort(vector<int>& foo){
  vector<int> temp;
  vector<vector<int> > bar(10,temp);
  //declaring vector<int> inside vector<vector> is 2meta4me
  int r;
  for(int i = 0; i < digits; i++){
    for(int j = 0; j < foo.size(); j++){//r = ith digit of foo[j]
      r = foo[j];
      for(int m = 0; m < i; m++){
	r = r/10;
      }
      if(i != digits){
	r = r%10;
      }
      bar[r].push_back(foo[j]);
    }
    for(int k = 0; k <= digits; k++){//add items from bar[j] into A
      foo.clear();
      for(int n = 0; n < bar.size(); n++){
	for(int p = 0; p < bar[n].size(); p++){
	  foo.push_back(bar[n][p]);
	}
      }
    }
    for( int l = 0; l < bar.size(); l++){//Clearing contents of bar
      bar[l].clear();
    }
  }
}
