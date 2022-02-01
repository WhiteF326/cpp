#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define all(x) x.begin(), x.end()
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;
#define query(t) for(int _ = 0; _ < t; _++)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)


int op(int a, int b){
  return min(a, b);
}
int e(){
  return INT_MAX;
}
int mapping(int f, int x){
  return min(f, x);
}
int composition(int f, int g){
  return min(f, g);
}
int id(){
  return INT_MAX;
}
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n, q; cin >> n >> q;
  vector<int> s(n), t(n), x(n);
  for(int i = 0; i < n; i++){
    cin >> s[i] >> t[i] >> x[i];
  }
  vector<int> p(q);
  for(int i = 0; i < q; i++){
    cin >> p[i];
  }

  lazy_segtree<int, op, e, int, mapping, composition, id> seg(q);
  for(int i = 0; i < n; i++){
    int l = lower_bound(all(p), s[i] - x[i]) - p.begin();
    int r = lower_bound(all(p), t[i] - x[i]) - p.begin();

    seg.apply(l, r, x[i]);
  }

  for(int i = 0; i < q; i++){
    int ans = seg.get(i);
    cout << (ans == INT_MAX ? -1 : ans) << endl;
  }
}
