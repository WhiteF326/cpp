#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n; cin >> n;
  vector<ll> r(n + 1, 0), x(n + 1, 0);
  for(int i = 0; i < n; i++){
    ll a; cin >> a;
    r[i + 1] = r[i] + a;
    x[i + 1] = max(x[i], r[i + 1]);
  }

  ll res = 0, cur = 0;
  for(int i = 0; i < n; i++){
    res = max(res, cur + x[i + 1]);
    cur += r[i + 1];
  }
  cout << res << endl;
}