/*
  William F. Sampson
  williamsampson44444@gmail.com
  wsampson
  Assignment 8: Breadth-First Search
  4/27/17
  main.cpp
  Full program for Breadth-First Search Program.
  Status: Complete
 */

#include <iostream>
#include <vector>
#include <queue>
#include <cctype>

using namespace std;

int main(){
  string input;
  vector<int> graph;
  vector<bool> color;
  vector<int> parent;
  vector<int> distance;
  while(cin >> input){//Initializing graph nodes
    for(int j = 0; j < input.size(); j++){
      if(input[j] >= '0' && input[j] <= '9'){
	graph.push_back(input[j] - 48);
      }else{
	graph.push_back(tolower(input[j]) - 87);
      }
      color.push_back(false);
      parent.push_back(-1);
      distance.push_back(0);
    }
  }
  const int side = input.size();//Useful number to have around
  queue<int> Q;
  Q.push(0);
  color[0] = true;
  //End of initialization
  
  //Explore/search
  int cur;
  vector<int> adj;
  while(!Q.empty()){
    cur = Q.front();//Dequeue next element
    Q.pop();
    //Could write getAdj(cur, graph.size()), don't feel like it.
    //Checking top
    if(cur - side >= 0 && graph[cur] < 7)
      adj.push_back(cur - side);
    //Checking bottom
    if(cur + side < graph.size() && graph[cur] % 4 < 2)
      adj.push_back(cur + side);
    //Checking left
    if(cur % side != 0 && graph[cur] % 8 < 4)
      adj.push_back(cur - 1);
    //Checking right
    if((cur + 1) % side != 0 && graph[cur] % 2 == 0)
      adj.push_back(cur + 1);

    for(int j = 0; j < adj.size(); j++){
      if(color[adj[j]] == false){
	color[adj[j]] = true;
	parent[adj[j]] = cur;
	distance[adj[j]] = distance[cur] + 1;
	Q.push(adj[j]);
      }
    }
    adj.clear();
  }
  
  vector<string> path;
  //Inserting path into vector with syntax: '(' + x + ', ' + y + ')'
  cur = graph.size()-1;
  string temp;
  while(cur != -1){
    temp = "(";
    temp += to_string(cur % side);
    temp += ", ";
    temp += to_string(cur / side);
    temp += ")";
    path.push_back(temp);
    cur = parent[cur];
  }
  
  //Read vector backwards to print path
  for(int i = path.size()-1; i >= 0; i--)
    cout << path[i] << endl;

  return 0;
}
