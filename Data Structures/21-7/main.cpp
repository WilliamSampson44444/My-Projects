/*
  William F. Sampson
  williamsampson44444@gmail.com
  wsampson
  Assignment 7: Binary Search tree
  4/25/17
  main.cpp
  Main function for Binary Search Tree program.
  Status: Complete
*/

#include <iostream>
#include "bstree.h"

using namespace std;

int main(){
  string input;
  int num;
  bstree bst;
  bool found;
  int temp;
  while(cin >> input){
    if(input[0] == '#'){
      getline(cin, input);//If comment, skip line
    }else{
      if(input == "insert"){
	cin >> num;
	bst.insert(num);
	cout << "inserted " << num << ".\n";
      }else if(input == "search"){
	cin >> num;
	if(bst.find(num)){
	  cout << num << " found." << endl;
	}else{
	  cout << num << " not found." << endl;
	}
      }else if(input == "delete"){
	cin >> num;
	found = bst.remove(num);
	if(found){
	  cout << "deleted " << num << ".\n";
	}else{
	  cout << "delete " << num << " - not found.\n";
	}
      }else if(input == "predecessor"){
	cin >> num;
	bst.getCessor(num, 'p');
      }else if(input == "successor"){
	cin >> num;
	bst.getCessor(num, 's');
      }else if(input == "min"){
	bst.getMin();
      }else if(input == "max"){
	bst.getMax();
      }else if(input == "inorder"){
	cout << "inorder traversal:\n";
	bst.DoInOrder();
	cout << endl;
      }else if(input == "preorder"){
	cout << "preorder traversal:\n";
	bst.DoPreOrder();
	cout << endl;
      }else if(input == "postorder"){
	cout << "postorder traversal:\n";
	bst.DoPostOrder();
	cout << endl;
      }
    }
  }
  return 0;
}
