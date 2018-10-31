/*
  William F. Sampson
  williamsampson44444@gmail.com
  wsampson
  Assignment 3: Quicksort
  3/2/17
  main.cpp
  Full program code for Quicksort Assignment. (Anything to avoid multifile!)
  Status: Complete.
  I'm quite pleased with this one, though I may have to ask how to "Take it off
  of Pengo for testing". I kept it small-ish this time.
 */

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

//Primary, self-calling QuickSort function
void QuickSort(vector<int>& foo, int p, int r);

//Lomuto Partition method
int LPartition(vector<int>& foo, int p, int r);

int main(){
  int input;
  vector<int> foo;
  while(cin >> input){
    foo.push_back(input);
  }
  QuickSort(foo, 0, foo.size()-1);//Quicksort called
  for(int i = 0; i < foo.size(); i++){
    cout << setfill('0') << setw(9) << foo[i] << endl;
  }
  return 0;
}

void QuickSort(vector<int>& foo, int p, int r){
  if(p<r){
    int q = LPartition(foo,p,r);
    QuickSort(foo,p,q-1);
    QuickSort(foo,q+1,r);
  }
}

int LPartition(vector<int>& foo, int p, int r){
  int temp;//MEDIAN OF 3 ALGORITHM
  if(r-p > 10){//Not sure what to compare to here, but it works
    int a = foo[p];
    int b = foo[(p+r)/2];
    int c = foo[r];
    if((a < c && a > b) || (a < b && a > c)){
      temp = foo[r];
      foo[r] = foo[p];
      foo[p] = temp;
    }else if((b < a && b > c) || (b < c && b > a)){
      temp = foo[(p+r)/2];
      foo[(p+r)/2] = foo[r];
      foo[r] = temp;
    }
  }
  //Actual Partitioning
  int x = foo[r];
  int i = p-1;
  for(int j = p; j < r; j++){
    if(foo[j] <= x){
      i++;
      temp = foo[i];
      foo[i] = foo[j];
      foo[j] = temp;
    }
  }
  temp = foo[i+1];
  foo[i+1] = foo[r];
  foo[r] = temp;
  return i+1;
}
