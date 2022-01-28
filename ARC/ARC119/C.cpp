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
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n; cin >> n;
  vector<ll> a(n);
  aryin(a, n);

  for(int i = 1; i < n; i += 2){
    a[i] = -a[i];
  }

  vector<ll> asum(all(a));
  for(int i = 1; i < n; i++) asum[i] += asum[i - 1];

  ll cur = 0;
  ll ans = 0;
  unordered_map<ll, int> m;
  for(ll v : asum) m[v]++;
  for(int i = 0; i < n; i++){
    ans += m[cur];
    cur += a[i];
    m[asum[i]]--;
  }

  cout << ans << endl;
}