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
#define chmin(a, b) a = min(a, b)


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n, m; cin >> n >> m;
  dsu d(n);
  vector<int> p(n);
  aryin(p, n);

  for(int i = 0; i < m; i++){
    int x, y; cin >> x >> y;
    d.merge(x - 1, y - 1);
  }

  int ans = 0;
  for(auto s : d.groups()){
    set<int> st;
    for(int v : s){
      st.insert(p[v] - 1);
    }
    for(int v : s){
      if(st.find(v) != st.end()){
        ans++;
      }
    }
  }

  cout << ans << endl;
}