#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
using ll = long long;
using ld = long double;

int main(){
  int n; cin >> n;
  ll c; cin >> c;
  vector<pair<ll, ll>> s(n * 2 + 1);
  s[0] = mp(0, 0);
  for(int i = 0; i < n; i++){
    ll a, b, c; cin >> a >> b >> c;
    s[i * 2 + 1] = mp(a, c);
    s[i * 2 + 2] = mp(b + 1, -c);
  }
  sort(s.begin(), s.end());

  ll ans = 0, t = 0;
  for(int i = 0; i < n * 2; i++){
    ans += (s[i + 1].first - s[i].first) * min(t, c);
    t += s[i + 1].second;
  }
  cout << ans << endl;
}