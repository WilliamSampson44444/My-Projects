/*
  William F. Sampson
  williamsampson44444@gmail.com
  wsampson
  Assignment 7: Binary Search Tree
  4/27/17
  bstree.cpp
  Binary Search Tree class function definitions for Binary Search Tree program.
  Status: Complete
 */

#include <iostream>
#include "bsnode.h"
#include "bstree.h"

using namespace std;

bsnode* bstree::search(bsnode* x, int key){
  if(x == NULL || x->getData() == key)
    return x;
  if(x->getData() > key){
    return search(x->getLeft(), key);
  }else{
    return search(x->getRight(), key);
  }
}

void bstree::insert(int key){
  bsnode* newNode = new bsnode(key);
  bsnode* prev = nullptr;
  bsnode* temp = root;
  while(temp != NULL){
    prev = temp;
    if(newNode->getData() < temp->getData()){
      temp = temp->getLeft();
    }else{
      temp = temp->getRight();
    }
  }
  newNode->setParent(prev);
  if(prev == NULL){
    root = newNode;
    return;
  }
  if(newNode->getData() < prev->getData()){
    prev->setLeft(newNode);
  }else{
    prev->setRight(newNode);
  }
}

bool bstree::remove(int key){
  bsnode* toRemove = search(root, key);
  if(toRemove == NULL){
    return false;
  }
  bsnode* target;
  if(toRemove->getLeft() == NULL || toRemove->getRight() == NULL){
    target = toRemove;
  }else{
    target = successor(toRemove);
  }
  bsnode* temp;
  if(target->getLeft() != NULL){//temp is null or pointer to only child
    temp = target->getLeft();
  }else{
    temp = target->getRight();
  }
  if(temp != NULL){//splicing target node
    temp->setParent(target->getParent());
  }
  if(target->getParent() == NULL){
    root = temp;
  }else{
    if(target == target->getParent()->getLeft()){
      target->getParent()->setLeft(temp);
    }else{
      target->getParent()->setRight(temp);
    }
  }//end splicing target node
  if(target != toRemove){
    toRemove->setData(target->getData());
  }
  delete target;
  return true;
}

bsnode* bstree::min(bsnode* x){
  if(x == NULL)
    return nullptr;
  while(x->getLeft() != NULL){
    x = x->getLeft();
  }
  return x;
}

bsnode* bstree::max(bsnode* x){
  if(x == NULL)
    return nullptr;
  while(x->getRight() != NULL){
    x = x->getRight();
  }
  return x;
}

void bstree::getMin(){
  if(min(root)){
    cout << "min is " << min(root)->getData() << ".\n";
  }else{
    cout << "An empty tree has no minimum." << endl;
  }
}

void bstree::getMax(){
  if(min(root)){
    cout << "max is " << max(root)->getData() << ".\n";
  }else{
    cout << "An empty tree has no maximum." << endl;
  }
}


void bstree::inOrder(bsnode* x){
  if(x == NULL){
    return;
  }
  inOrder(x->getLeft());
  cout << x->getData() << " ";
  inOrder(x->getRight());
}

void bstree::preOrder(bsnode* x){
  if(x == NULL){
    return;
  }
  cout << x->getData() << " ";
  preOrder(x->getLeft());
  preOrder(x->getRight());
}

void bstree::postOrder(bsnode* x){
  if(x == NULL){
    return;
  }
  postOrder(x->getLeft());
  postOrder(x->getRight());
  cout << x->getData() << " ";
}

bsnode* bstree::predecessor(bsnode* x){
  if(x->getLeft() != NULL)
    return max(x->getLeft());
  bsnode* temp = x->getParent();
  while(temp != NULL && x == temp->getLeft()){
    x = temp;
    temp = temp->getParent();
  }
  return temp;
}

bsnode* bstree::successor(bsnode* x){
  if(x->getRight() != NULL)
    return min(x->getRight());
  bsnode* temp = x->getParent();
  while(temp != NULL && x == temp->getRight()){
    x = temp;
    temp = temp->getParent();
  }
  return temp;
}

void bstree::getCessor(int x, char y){
  bsnode* temp = search(root, x);
  if(temp == NULL){
    cout << x << " not in tree.\n";
  }else if(y == 'p'){
    temp = predecessor(temp);
    if(temp == NULL){
      cout << "no predecessor for " << x << ".\n";
    }else{
      cout << x << " predecessor is " << temp->getData() << ".\n";
    }
  }else if(y == 's'){
    temp = successor(temp);
    if(temp == NULL){
      cout << "no successor for " << x << ".\n";
    }else{
      cout << x << " successor is " << temp->getData() << ".\n";
    }
  }
}
