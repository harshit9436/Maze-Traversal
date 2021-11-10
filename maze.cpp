#include <iostream>
#include <fstream>
#include <vector>
#include<tuple>
#include <string>
using namespace std;

vector<char> traverseMaze(string mazefile){
    ifstream fin;
    fin.open(mazefile);
    string line;
    vector<string> l;
    while (fin) {
 
        // Read a Line from File
        getline(fin, line);
 
        // Print line in Console
        l.push_back(line);
    }
    fin.close();
    l.pop_back();
    for(int i =0;i<l.size();i++){
        l[i] = l[i].substr(0,l[i].size());
    }
    vector<vector<char>> maze;
    for(int i=0;i<l.size();i++){
        vector<char> s;
        for(int j =0;j< l[0].size();j++){
            if(l[i][j]!=' '){
                s.push_back(l[i][j]);
            }
        }
        maze.push_back(s);
    }
    bool b = true;
    tuple<int,int> start;
    for(int i=0;i<maze.size();i++){
        for (int j=0;j<maze[0].size();j++){
            if(maze[i][j]=='S'){
                start = make_tuple(i,j);
            }
        }
    }
    int y = get<0>(start);
    int x = get<1>(start);


    vector<char> path ;
    while (b)
    {
        if(x<l[0].size()-1 && (maze[y][x + 1] == '_' || maze[y][x + 1] == 'E')){
            x+=1;
            path.push_back('R');
            if (maze[y][x] == 'E'){
                b=false;
                return path;
            }
            maze[y][x] = '1';
        }else if (y>0 && (maze[y - 1][x] == '_' || maze[y - 1][x] == 'E')){
            y = y - 1;
            path.push_back('U');
            if (maze[y][x] == 'E'){
                b=false;
                return path;
            }
            maze[y][x] = '1';
        }else if(x>0 && (maze[y][x - 1] == '_' || maze[y][x - 1] == 'E')){
             x -= 1;
             path.push_back('L');
             if (maze[y][x] == 'E'){
                b=false;
                return path;
            }
            maze[y][x] = '1';
        }else if(y < l.size()-1 && (maze[y + 1][x] == '_' || maze[y + 1][x] == 'E')){
            y+=1;
            path.push_back('D');
            if (maze[y][x] == 'E'){
                b=false;
                return path;
            }
            maze[y][x] = '1';
        } else if(path.size()!=0 && path[path.size()-1]=='R'){
            x-=1;
            path.pop_back();
        } else if(path.size()!=0 && path[path.size()-1]=='U'){
            y+=1;
            path.pop_back();
        } else if(path.size()!=0 && path[path.size()-1]=='L'){
            x+=1;
            path.pop_back();
        }  else if(path.size()!=0 && path[path.size()-1]=='D'){
            y-=1;
            path.pop_back();
        } else{
            b=false;
            return path;
        }
    }
}

int main(){
    
    vector<char> maze = traverseMaze("maze.txt");

    for (auto i = maze.begin(); i != maze.end(); ++i){
        cout << *i << " ";
    }
    
    return 0;
}