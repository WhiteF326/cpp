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
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)


template <typename T>
struct SegTree{
  const T INF = numeric_limits<T>::max();
  int n;
  vector<T> dat;
  SegTree(int n_) : n(), dat(n_ * 4, 0) {
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
  
  int tt; cin >> tt;
  query(tt){
    int n; cin >> n;
    vector<int> a(n);
    aryin(a, n);

    int start = 0;
    vector<int> ans;

    //
  }
}