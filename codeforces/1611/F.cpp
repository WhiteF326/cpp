#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


template <typename T>
struct SegTree{
  const T INF = numeric_limits<T>::max();
  int n;
  vector<T> dat;
  SegTree(int n_) : n(), dat(n_ * 4, INF) {
    int x = 1;
    while (n_ > x) {
      x *= 2;
    }
    n = x;
  }
  void update(int i, T x) {
    i += n - 1;
    dat[i] = x;
    while (i > 0) {
      i = (i - 1) / 2;
      dat[i] = min(dat[i * 2 + 1], dat[i * 2 + 2]);
    }
  }

  T prod(int a, int b) { return prod_sub(a, b, 0, 0, n); }
  T prod_sub(int a, int b, int k, int l, int r) {
    if (r <= a || b <= l) {
      return INF;
    } else if (a <= l && r <= b) {
      return dat[k];
    } else {
      T vl = prod_sub(a, b, k * 2 + 1, l, (l + r) / 2);
      T vr = prod_sub(a, b, k * 2 + 2, (l + r) / 2, r);
      return min(vl, vr);
    }
  }
};
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int t; cin >> t;
  query(t){
    int n; cin >> n;
    ll s; cin >> s;
    vector<ll> v(n);
    aryin(v, n);
    vector<ll> vs(all(v));
    for(int i = 1; i < n; i++) vs[i] += vs[i - 1];

    SegTree<ll> seg(n);
    for(int i = 0; i < n; i++) seg.update(i, vs[i]);

    int ansl = n + 1, ansr = -1;
    for(int i = 0; i < n; i++){
      int l = i - 1, r = n;
      while(r - l > 1){
        int mid = (l + (r - l) / 2) + 1;
        if(seg.prod(i, mid) + s >= 0){
          l = mid - 1;
        }else{
          r = mid - 1;
        }
      }
      // i, l が条件を満たす
      if(ansr - ansl < l - i){
        ansr = l;
        ansl = i;
      }
      // to next
      s -= v[i];
    }
    if(ansl > ansr){
      cout << -1 << endl;
    }else{
      cout << ansl + 1 << " " << ansr + 1 << endl;
    }
  }
}