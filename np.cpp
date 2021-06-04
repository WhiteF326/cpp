#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

vector<vector<int>> stage(9, vector<int>(9, 0));

int dfs(int pt){
  int x = pt % 9, y = pt / 9;
  if(pt == 81){
    // end
    for(int i = 0; i < 9; i++){
      for(int j = 0; j < 9; j++){
        cout << stage[i][j];
      }cout << endl;
    }
    return 0;
  }
  pt++;
  if(stage[y][x]){
    dfs(pt);
  }else{
    vector<bool> usable(10, true);
    for(int i = 0; i < 9; i++){
      usable[stage[y][i]] = false;
      usable[stage[i][x]] = false;
    }
    for(int i = 0; i < 3; i++){
      for(int j = 0; j < 3; j++){
        usable[stage[(y / 3) * 3 + i][(x / 3) * 3 + j]] = false;
      }
    }
    for(int i = 1; i <= 9; i++){
      if(usable[i]){
        stage[y][x] = i;
        dfs(pt);
        stage[y][x] = 0;
      }
    }
  }
  pt--;
  return 0;
}

int main(){
  for(int i = 0; i < 9; i++){
    string s; cin >> s;
    for(int j = 0; j < 9; j++){
      stage[i][j] = stoi(s.substr(j, 1));
    }
  }

  //dfs
  dfs(0);
}