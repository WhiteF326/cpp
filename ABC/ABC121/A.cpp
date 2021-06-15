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
  int r, c; cin >> r >> c;

  cout << h * w - r * w - h * c + r * c << endl;
}