#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j);
using ll = long long;
using ld = long double;

int main(){
  int n, m; cin >> m >> n;
  vector<vector<int>> stage(n, vector<int>(m));
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++) cin >> stage[i][j];
  }
  
}