#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j);
using ll = long long;
using ld = long double;

const ll modv = 1000000007;

int main(){
  int n, ma, mb; cin >> ma >> mb;
  vector<vector<int>> y(n, vector<int>(3, 0));
  for(int i = 0; i < n; i++){
    for(int j = 0; j < 3; j++) cin >> y[i][j];
  }
  // knapzack
}
