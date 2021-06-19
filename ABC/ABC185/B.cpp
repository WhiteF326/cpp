#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j)
using ll = long long;
using ld = long double;

int main(){
  int n, m, t; cin >> n >> m >> t;
  int xn = n;
  int la = 0;
  bool ans = true;
  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    n -= (a - la);
    la = b;
    if(n <= 0) ans = false;
    n += (b - a);
    if(n >= xn) n = xn;
  }
  n -= (t - la);
  if(n <= 0) ans = false;
  cout << (ans ? "Yes" : "No") << endl;
}