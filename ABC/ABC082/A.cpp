#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(i, j) make_pair(i, j);
using ll = long long;
using ld = long double;

int main(){
  int a, b; cin >> a >> b;
  int ans = a + b;
  ans += ans % 2;
  cout << ans / 2 << endl;
}