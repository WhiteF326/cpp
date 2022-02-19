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
  
  int n, m; cin >> n >> m;
  vector<ll> a(n);
  aryin(a, n);
  vector<ll> b(n);
  aryin(b, n);
  
  dsu d(n);
  for(int i = 0; i < m; i++){
    int x, y;
    cin >> x >> y;
    d.merge(x - 1, y - 1);
  }

  auto v = d.groups();
  bool ans = true;
  for(auto s : v){
    ll as = 0, bs = 0;
    for(auto t : s){
      as += a[t];
      bs += b[t];
    }
    if(as != bs) ans = false;
  }
  cout << (ans ? "Yes" : "No") << endl;
}
