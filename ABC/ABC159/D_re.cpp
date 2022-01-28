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
  vector<int> a(n);
  aryin(a, n);

  unordered_map<int, ll> mx;
  
  for(int v : a) mx[v]++;
  ll ans = 0;
  for(auto p : mx) ans += p.second * (p.second - 1) / 2;
  for(int v : a){
    ll res = ans;
    res -= mx[v] * (mx[v] - 1) / 2;
    res += (mx[v] - 1) * (mx[v] - 2) / 2;
    cout << res << endl;
  }
}