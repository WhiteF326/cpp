#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j)
using ll = long long;
using ld = long double;

int main(){
  int n; cin >> n;
  vector<vector<bool>> g(n, vector<bool>(n, true));

  if(n % 2){
    for(int i = 0; i < (n / 2); i++){
      g[i][n - i - 2] = false;
    }
  }else{
    for(int i = 0; i < (n / 2); i++){
      g[i][n - i - 1] = false;
    }
  }

  vector<pair<int, int>> anslist;

  for(int i = 0; i < n - 1; i++){
    for(int j = i + 1; j < n; j++){
      if(g[i][j]){
        anslist.push_back(mp(i, j));
      }
    }
  }
  cout << anslist.size() << endl;
  for(auto itr = anslist.begin(); itr != anslist.end(); itr++){
    cout << itr->first + 1 << " " << itr->second + 1 << endl;
  }
}