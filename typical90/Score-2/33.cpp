#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  int h, w; cin >> h >> w;
  if(h == 1 || w == 1) cout << h * w << endl;
  else cout << (int)(ceil(h / 2.0) * ceil(w / 2.0)) << endl;
}