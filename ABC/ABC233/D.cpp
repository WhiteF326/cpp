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
#define query(t) for(int _ = 0; _ < t; _++)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n; cin >> n;
  ll k; cin >> k;
  vector<ll> a(n); aryin(a, n);

  vector<ll> asum(all(a));
  for(int i = 1; i < n; i++) asum[i] += asum[i - 1];

  map<ll, int> ctr;
  for(ll v : asum) ctr[v]++;

  ll cur = k;
  ll ans = 0;
  for(int i = 0; i < n; i++){
    ans += ctr[cur];
    ctr[asum[i]]--;
    cur += a[i];
  }

  cout << ans << endl;
}