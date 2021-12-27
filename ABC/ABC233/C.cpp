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

int n;
vector<vector<ll>> a(100000);
ll x;
ll ans = 0;

void dfs(int p, ll v){
  if(p == n && v == 1){
    ans++;
    return;
  }
  for(ll z : a[p]){
    if(v % z == 0 && v >= z){
      dfs(p + 1, v / z);
    }
  }
}

int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  cin >> n;
  cin >> x;

  for(int i = 0; i < n; i++){
    int l; cin >> l;
    vector<ll> x(l);
    for(int j = 0; j < l; j++){
      ll v; cin >> v;
      x[j] = v;
    }
    a[i] = x;
  }

  dfs(0, x);

  cout << ans << endl;
}