/*
  William F. Sampson
  wfsampson
  williamsampson44444@gmail.com
  CS23 Assigmnet 1: Unique Lexicography
  Due: 2/10/17
  Status: Complete! Takes about 10 seconds to run with the inaugural addresses.
  Function: Given files containing words, prints a set of each word found in the
  final file which is not used in the preceding files.
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

//MAIN FUNCTION START
int main(int argc, char* argv[]){
  vector<string> unique;
  vector<string> repeat;
  string currentFile;
  ifstream fin;
  string fileName;
  char next;
  string temp;
  int i = 0;
  //INPUT DELINEATION INTO STRINGS IN VECTORS
  for(int b = 1; b < argc; b++){//while(cin >> fileName){
    unique.clear(); //Resetting unique
    fin.open(argv[b]);
    if(fin.fail()){//Error detector
      cout << "Input file failed to open.\n";
      exit(-1);
    }
    currentFile = "";
    while (fin.get(next)){
      if(next >= 'A' && next <= 'Z'){//Correcting case
	next += 'a' - 'A';
      }
      if(next >= 'a' && next <= 'z'){//Adding a character
	currentFile += next;
      }else if(next == 39){
	currentFile += next;
      }else{//Or adding a space
	currentFile += '\n';
      }
      i++;
    }
    //I've never used istringstreams before! :D
    istringstream iss (currentFile);//Places each space-delineated word in iss
    while(iss >> temp){
      //Places each word in vector of strings
      unique.push_back(temp);
    }
    int k;
    bool rpt;
    //n^2 loop to remove repeats from unique
    for(int m=0; m < unique.size(); m++){
      k = 0;
      rpt = false;
      while(!rpt && k < repeat.size()){
	//cout << "Checking for repeat!" << endl;//Debugging
	if(repeat[k] == unique[m]){
	  unique.erase(unique.begin() + m);//Possible OB1 error source
	  m--;
	  rpt = true;
	  //cout << "Repeat found!" << endl;//Debugging
	}
	k++;
      }
    }
    //Adding contents of unique as possible repeats.
    for(int h = 0; h < unique.size(); h++){
      repeat.push_back(unique[h]);
    }
    fin.close();//Resetting fin for next file.
  }
  //SORTING UNIQUE WORDS
  sort(unique.begin(), unique.end());
  /*Turning Unique into a Set (Probably should have been done during the big
    fin while loop but I can't be bothered)
  */
  for(int z = 0; z < unique.size()-1; z++){
    if(unique[z] == unique[z+1]){
      unique.erase(unique.begin() + z);
      z--;
    }
  }
   //Listing unique words
  for(int a=0; a < unique.size(); a++){
    cout << unique[a] << endl;
  }
  // END OF PROGRAM
  return 0;
}
