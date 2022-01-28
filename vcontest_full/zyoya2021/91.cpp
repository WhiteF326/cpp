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
  ll c; cin >> c;
  vector<pair<ll, ll>> s(n * 2 + 1);
  s[0] = mp(0, 0);
  for(int i = 0; i < n; i++){
    ll a, b, c; cin >> a >> b >> c;
    s[i * 2 + 1] = {a, c};
    s[i * 2 + 2] = {b + 1, -c};
  }
  sort(all(s));

  ll ans = 0, t = 0;
  for(int i = 0; i < n * 2; i++){
    ans += (s[i + 1].first - s[i].first) * min(t, c);
    t += s[i + 1].second;
  }

  cout << ans << endl;
}