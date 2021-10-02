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
  int n; cin >> n;
  int m; cin >> m;
  vector<pair<int, ll>> ac(m);
  map<int, ll> cl;
  ll mc = LLONG_MAX;
  for(int i = 0; i < n; i++){
    int a; ll c;
    cin >> a >> c;
    ac[i].first = a, ac[i].second = c;
    mc = min(mc, c);
    if(!cl[a]){
      cl[a] = c;
    }else{
      cl[a] = min(cl[a], c);
    }
  }

  multiset<ll> mxl;
  for(auto p : cl) mxl.insert(p.second);

  ll ans = LLONG_MAX;
  for(int i = 0; i < m; i++){
    //
  }
}