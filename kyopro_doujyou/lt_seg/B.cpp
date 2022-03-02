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
// #define prod(t) for(int _ = 0; _ < t; _++)
#define aryin(a, n)           \
  for (int i = 0; i < n; i++) \
    cin >> a[i];
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)

#define rep(i, a, b) for (int i = a; i < b; i++)

template <typename T>
struct Segtree2D
{
  int H, W;
  vector<vector<T>> dat;
  using func_t = function<T(T, T)>;
  T def;
  func_t fun;
  Segtree2D(vector<vector<T>> &f, T def, func_t fun) : def(def), fun(fun)
  {
    H = W = 1;
    while (H < (int)f.size())
      H <<= 1;
    while (W < (int)f[0].size())
      W <<= 1;
    dat.assign(2 * H - 1, vector<T>(2 * W - 1, def));
    init(f);
  }
  void init(vector<vector<T>> &f)
  {
    rep(i, 0, (int)f.size()) rep(j, 0, (int)f[0].size()) dat[i + H - 1][j + W - 1] = f[i][j];
    for (int i = 2 * H - 2; i > H - 2; i--)
      for (int j = W - 2; j >= 0; j--)
        dat[i][j] = fun(dat[i][2 * j + 1], dat[i][2 * j + 2]);
    for (int i = H - 2; i >= 0; i--)
      rep(j, 0, 2 * W - 1)
          dat[i][j] = fun(dat[2 * i + 1][j], dat[2 * i + 2][j]);
  }
  T get_h(int li, int lj, int ri, int rj, int si, int ti, int k)
  {
    if (ri <= si or ti <= li)
      return def;
    if (li <= si and ti <= ri)
      return get_w(lj, rj, 0, W, k, 0);
    const int mi = (si + ti) / 2;
    return fun(get_h(li, lj, ri, rj, si, mi, 2 * k + 1), get_h(li, lj, ri, rj, mi, ti, 2 * k + 2));
  }
  T get_w(int lj, int rj, int sj, int tj, int i, int k)
  {
    if (rj <= sj or tj <= lj)
      return def;
    if (lj <= sj and tj <= rj)
      return dat[i][k];
    const int mj = (sj + tj) / 2;
    return fun(get_w(lj, rj, sj, mj, i, 2 * k + 1), get_w(lj, rj, mj, tj, i, 2 * k + 2));
  }
  T get(int li, int lj, int ri, int rj)
  {
    return get_h(li, lj, ri, rj, 0, H, 0);
  }
};

int op(int a, int b)
{
  return a ^ b;
}
int e()
{
  return 0;
}

int main()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int q;
  cin >> q;

  vector<vector<int>> v = {
      {1, 2, 3, 4, 5},
      {6, 7, 8, 9, 10},
      {11, 12, 13, 14, 15},
      {16, 17, 18, 19, 20},
      {21, 22, 23, 24, 25}};

  // SegmentTree2D<int, op, e> st(v);
  Segtree2D<int> st(v, 0, [](int a, int b){
    return a ^ b;
  });

  while(q--){
    int a, b, c, d; cin >> a >> b >> c >> d;
    cout << st.get(a, b, c, d) << endl;
  }
}