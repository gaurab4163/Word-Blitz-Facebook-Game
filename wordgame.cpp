#include <bits/stdc++.h>

using namespace std;

struct Dictionary {
      Dictionary() {
        ifstream input ("words3.txt");
        for (string line; getline(input, line); ) {
          words.insert(line);
        }
      }
      set<string> words;
      bool contains(string& word){
           return words.count(word);
        }
};

Dictionary dictionary;
int totalWords=0;

void recurse(string array[][4],string currentWord,vector<bool> history,int i,int j ){

    history[(i*4)+j]=true;
    currentWord+=array[i][j];
    if(dictionary.contains(currentWord))
        {cout<<currentWord<<"\t";totalWords++;}
    if(j!=3){//east
        if(!history[(i*4)+j+1])
            recurse(array,currentWord,history,i,j+1);
        if(i!=0){//north-east
            if(!history[(i*4)+j-3])
                recurse(array,currentWord,history,i-1,j+1);
        }
    }
    if(j!=0){//west
        if(!history[(i*4)+j-1])
            recurse(array,currentWord,history,i,j-1);
        if(i!=3){//south-west
            if(!history[(i*4)+j+3])
                recurse(array,currentWord,history,i+1,j-1);
        }
    }
    if(i!=0){//north
        if(!history[(i*4)+j-4])
            recurse(array,currentWord,history,i-1,j);
        if(j!=0){//north-west
            if(!history[(i*4)+j-5])
                recurse(array,currentWord,history,i-1,j-1);
        }
    }
    if(i!=3){//south
        if(!history[(i*4)+j+4])
            recurse(array,currentWord,history,i+1,j);
        if(j!=3){//south-east
            if(!history[(i*4)+j+5])
                recurse(array,currentWord,history,i+1,j+1);
        }
    }
}

int main()
{
    cout<<"loaded\n";
    string array[4][4];
    cout<<"enter letters: \n";
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cin>>array[i][j];
        }
    }

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            string currentWord="";
            vector<bool> history(16,false);
            recurse(array,currentWord,history, i,j);
        }
    }
    cout<<"\n\nTotal no of words:  "<<totalWords<<endl;
 }
