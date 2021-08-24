#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define const constexpr
#define pdesc(t) t, vector<t>, greater<t>
#define chmin(a, b) a = min(a, b)
using ll = long long;
using ld = long double;

int main(){
  string s; cin >> s;
  int n = (int)s.size();

  ll ans = 0;
  vector<ll> c(2020, 0);
  c[0] = 1;
  int t = 0, p = 1;
  for(int i = n - 1; i >= 0; i--){
    t = (t + (s[i] - '0') * p) % 2019;
    ans += c[t];

    p = (p * 10) % 2019;
    c[t]++;
  }
  cout << ans << endl;
}