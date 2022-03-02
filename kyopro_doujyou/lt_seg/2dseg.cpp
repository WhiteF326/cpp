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


template <class S, S(*op)(S, S), S(*e)()>
class Full2DSegTree {
public:
  Full2DSegTree(vector<vector<S>> &f) {
    h = 1 << atcoder::internal::ceil_pow2(f.size());
    w = 1 << atcoder::internal::ceil_pow2(f[0].size());

    d.assign(2 * h - 1, vector<S>(2 * w + 1, e()));

    for(int i = 0; i < f.size(); i++){
      for(int j = 0; j < f[0].size(); j++){
        d[i + h - 1][j + w - 1] = f[i][j];
      }
    }
    for(int i = 2 * h - 2; i > h - 2; i--){
      for(int j = w - 2; j >= 0; j--){
        d[i][j] = op(d[i][2 * j + 1], d[i][2 * j + 2]);
      }
    }
    for(int i = h - 2; i >= 0; i--){
      for(int j = 0; j < 2 * w - 1; j++){
        d[i][j] = op(d[2 * i + 1][j], d[2 * i + 2][j]);
      }
    }
  }

  S get_h(int li, int lj, int ri, int rj, int si, int ti, int k) {
    if (ri <= si or ti <= li)
      return e();
    if (li <= si and ti <= ri)
      return get_w(lj, rj, 0, w, k, 0);
    const int mi = (si + ti) / 2;
    return op(
      get_h(li, lj, ri, rj, si, mi, 2 * k + 1),
      get_h(li, lj, ri, rj, mi, ti, 2 * k + 2)
    );
  }
  S get_w(int lj, int rj, int sj, int tj, int i, int k) {
    if (rj <= sj or tj <= lj)
      return e();
    if (lj <= sj and tj <= rj)
      return d[i][k];
    const int mj = (sj + tj) / 2;
    return op(
      get_w(lj, rj, sj, mj, i, 2 * k + 1),
      get_w(lj, rj, mj, tj, i, 2 * k + 2)
    );
  }
  S get(int li, int lj, int ri, int rj) {
    return get_h(li, lj, ri, rj, 0, h, 0);
  }

private:
  int h, w;
  vector<vector<S>> d;
};

int op(int a, int b){
  return a ^ b;
}
int e(){
  return 0;
}
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int q; cin >> q;
  
  vector<vector<ll>> v(100, vector<ll>(100, 0));
  
  query(q){
    int t; cin >> t;
    if(t == 1){
      int l, r; ll h;
      cin >> l >> r >> h;
    }
  }
}
