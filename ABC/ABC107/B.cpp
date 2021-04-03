#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<char>> tbl(h, vector<char>(w));
  
  for(int i = 0; i < h; i++){
    string tmp; cin >> tmp;
    for(int j = 0; j < w; j++){
      tbl[i][j] = tmp.at(j);
    }
  }
  
  vector<int> exth(0);
  vector<int> extw(0);
  for(int i = 0; i < h; i++){
    int chk = 0;
    for(int j = 0; j < w; j++){
      if(tbl[i][j] == '.'){
        chk++;
      }
    }
    if(chk != w){
      exth.push_back(i);
    }
  }
  for(int j = 0; j < w; j++){
    int chk = 0;
    for(int i = 0; i < exth.size(); i++){
      if(tbl[exth[i]][j] == '.'){
        chk++;
      }
    }
    if(chk < exth.size()){
      extw.push_back(j);
    }
  }
  for(int i = 0; i < exth.size(); i++){
    for(int j = 0; j < extw.size(); j++){
      cout << tbl[exth[i]][extw[j]];
    }
  	if(i != exth.size() - 1){
      cout << endl;
    }
  }
}