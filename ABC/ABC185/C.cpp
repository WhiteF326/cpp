#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j)
using ll = long long;
using ld = long double;

int main(){
  vector<vector<ll>> c(2001, vector<ll>(2001, 0));
  c[0][0] = 1;
  for(int i = 1; i < 2001; i++){
    c[i][0] = 1;
    for(int j = 1; j < 2001; j++){
      c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
    }
  }
  int l; cin >> l;
  ll ans = 0;
  cout << c[l - 1][11] << endl;
}