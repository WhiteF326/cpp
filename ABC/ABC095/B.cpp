#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(i, j) make_pair(i, j);
using ll = long long;
using ld = long double;

int main(){
  int n, x; cin >> n >> x;
  int res = INT_MAX, ans = 0;
  for(int i = 0; i < n; i++){
    int m; cin >> m;
    x -= m;
    res = min(res, m);
    ans++;
  }
  ans += x / res;
  cout << ans << endl;
}