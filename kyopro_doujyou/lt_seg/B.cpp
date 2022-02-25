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


int ceil_pow2(int n) {
  int x = 0;
  while ((1U << x) < (unsigned int)(n)) x++;
  return x;
}
ll op(ll a, ll b){
  return max(a, b);
}
ll e(){
  return 0LL;
}

template<class S, S (*op)(S, S), S (*e)()>
class Full2DSegTree {
  public:
    segtree() : segtree(0) {}
    explicit segtree(int h, int w) : segtree(h, w, e()) {}
    explicit segtree(const vector<vector<S>>& v) : _h, _w(int(v.size())) {
      log = ceil_pow2(_n);
      size = 1 << log;
      d = vector<segtree<S, op, e>>(size * 2, segtree<S, op, e>(_n));
      for(int i = 0; i < _n; i++){
        //
      }
    }
  
  private:
    int _h, _w, size, log;
};

int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int q; cin >> q;
  query(q){
    //
  }
}