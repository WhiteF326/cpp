#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  int n; cin >> n;
  vector<int> d(n);
  for(int i = 0; i < n; i++) cin >> d[i];
  vector<int> ds(n, d[n - 1]);
  for(int i = n - 2; i >= 0; i--) ds[i] = ds[i + 1] + d[i];
  int ans = 0;
  for(int i = 0; i < n; i++){
    ans += (ds[i] - d[i]) * d[i];
  }
  cout << ans << endl;
}