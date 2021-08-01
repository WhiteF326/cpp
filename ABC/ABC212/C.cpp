#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;

int main(){
  int n, m; cin >> n >> m;
  vector<int> a(n), b(m);
  for(int i = 0; i < n; i++) cin >> a[i];
  sort(all(a));
  for(int i = 0; i < m; i++) cin >> b[i];
  sort(all(b));

  int ans = INT_MAX;
  for(int i = 0; i < n; i++){
    int p = lower_bound(all(b), a[i]) - b.begin();
    for(int j = max(0, p - 2); j <= min(m - 1, p + 2); j++){
      ans = min(ans, abs(a[i] - b[j]));
    }
  }
  cout << ans << endl;
}