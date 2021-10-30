#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define const constexpr
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;
#define query(t) for(int _ = 0; _ < t; _++)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


int main(){
  int n, t; cin >> n >> t;
  vector<ll> a(n); aryin(a, n);

  vector<ll> m(n, a[0]);
  for(int i = 1; i < n; i++) m[i] = min(m[i - 1], a[i]);
  vector<ll> p(n, 0);
  for(int i = 0; i < n; i++) p[i] = a[i] - m[i];

  int x = *max_element(all(p));

  int ans = 0;
  map<ll, int> ml;
  for(int i = 0; i < n; i++){
    if(ml[a[i] - x]) ans++;
    ml[a[i]]++;
  }

  cout << ans << endl;
}