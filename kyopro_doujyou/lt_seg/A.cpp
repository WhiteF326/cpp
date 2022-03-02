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
  return a | b;
}
int e(){
  return 0;
}
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n; cin >> n;
  string s; cin >> s;
  vector<int> p(n);
  for(int i = 0; i < n; i++) p[i] = (1 << (s[i] - 'a'));

  segtree<int, op, e> seg(p);

  auto popcount = [](int v){
    int res = 0;
    while(v){
      res += v & 1;
      v >>= 1;
    }
    return res;
  };

  int q; cin >> q;
  query(q){
    int t; cin >> t;
    if(t == 1){
      int i; char c; cin >> i >> c;
      seg.set(i - 1, 1 << (c - 'a'));
    }else{
      int l, r; cin >> l >> r;
      cout << popcount(seg.prod(l - 1, r)) << "\n";
    }
  }

  fflush(stdout);
}
