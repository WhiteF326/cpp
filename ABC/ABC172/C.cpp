#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  int n, m, k; cin >> n >> m >> k;
  vector<ll> a(n), b(m);
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < m; i++) cin >> b[i];
  // 累積和
  for(int i = 1; i < n; i++) a[i] += a[i - 1];
  for(int i = 1; i < m; i++) b[i] += b[i - 1];
  // aを選ばない場合を先に処理
  ll ans = 0;
  for(int i = 0; i < m; i++){
    if(b[i] <= k) ans = i + 1;
  }
  // aは全列挙
  for(int i = 0; i < n; i++){
    if(k < a[i]) break;
    // aから選択する処理
    ll kt = k - a[i];
    ll res = i + 1;
    // bは二分探索で決定
    ll bc = upper_bound(b.begin(), b.end(), kt) - b.begin();
    res += bc;
    ans = max(ans, res);
  }
  cout << ans << endl;
}