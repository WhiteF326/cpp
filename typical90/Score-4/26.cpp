// DSU is difficult

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  int n; cin >> n;
  vector<vector<int>> stage(1001, vector<int>(1001, 0));
  for(int i = 0; i < n; i++){
    int lx, ly, rx, ry; cin >> lx >> ly >> rx >> ry;
    stage[ly][lx]++;
    stage[ly][rx]--;
    stage[ry][lx]--;
    stage[ry][rx]++;
  }

  for(int y = 0; y <= 1000; y++){
    for(int x = 1; x <= 1000; x++){
      stage[y][x] += stage[y][x - 1];
    }
  }
  for(int y = 1; y <= 1000; y++){
    for(int x = 0; x <= 1000; x++){
      stage[y][x] += stage[y - 1][x];
    }
  }
  
  map<int, int> v;
  for(int y = 0; y <= 1000; y++){
    for(int x = 0; x <= 1000; x++){
      v[stage[y][x]]++;
    }
  }

  for(int i = 1; i <= n; i++){
    cout << v[i] << endl;
  }
}