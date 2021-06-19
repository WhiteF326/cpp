#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j)
using ll = long long;
using ld = long double;

int main(){
  int w, a, b; cin >> w >> a >> b;
  if(a <= b && b <= a + w && a + w <= b + w) cout << 0 << endl;
  else cout << min(abs(a - b - w), abs(b - a - w)) << endl;
}