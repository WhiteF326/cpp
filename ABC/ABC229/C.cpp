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
  int n, w; cin >> n >> w;
  vector<pair<int, int>> v(n);
  for(int i = 0; i < n; i++){
    int a, b; cin >> a >> b;
    v[i] = mp(a, b);
  }
  sort(all(v), [](pair<int, int> a, pair<int, int> b){
    return a > b;
  });

  ll ans = 0;
  for(int i = 0; i < n; i++){
    ans += (ll)v[i].first * (ll)min(w, v[i].second);
    w -= v[i].second;
    if(w <= 0) break;
  }

  cout << ans << endl;
}