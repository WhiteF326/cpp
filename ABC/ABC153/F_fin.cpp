#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define const constexpr
#define pdesc(t) t, vector<t>, greater<t>
#define chmin(a, b) a = min(a, b)
using ll = long long;
using ld = long double;

template <typename T>
struct BIT {
  int n;
  vector<T> bit[2];
  BIT(int n_) { init(n_); }
  void init(int n_) {
    n = n_ + 1;
    for (int p = 0; p < 2; p++) bit[p].assign(n, 0);
  }
  void add_sub(int p, int i, T x) {
    for (int idx = i; idx < n; idx += (idx & -idx)) {
      bit[p][idx] += x;
    }
  }
  void add(int l, int r, T x) {
    add_sub(0, l, -x * (l - 1));
    add_sub(0, r, x * (r - 1));
    add_sub(1, l, x);
    add_sub(1, r, -x);
  }
  T sum_sub(int p, int i) {
    T s(0);
    for (int idx = i; idx > 0; idx -= (idx & -idx)) {
      s += bit[p][idx];
    }
    return s;
  }
  T sum(int i) { return sum_sub(0, i) + sum_sub(1, i) * i; }
};

int main(){
  ifstream ifs("in.txt");
  int n, d, a; ifs >> n >> d >> a;
  vector<pair<ll, ll>> vset(n);
  for(int i = 0; i < n; i++) ifs >> vset[i].first >> vset[i].second;

  sort(all(vset));

  vector<ll> x(n), h(n);
  BIT<ll> bit(n);

  for(int i = 0; i < n; i++){
    x[i] = vset[i].first;
    h[i] = vset[i].second;
    bit.add(i + 1, i + 1, vset[i].second);
  }

  ll ans = 0;
  for(int i = 0; i < n; i++){
    if(i >= 1 && bit.sum(i + 1) - bit.sum(i) >= h[i]) continue;
    ll need = 0;
    if(i >= 1){
      need = h[i] - (bit.sum(i + 1) - bit.sum(i));
    }else{
      need = h[i] - bit.sum(i + 1);
    }
    need = ceil(need / (ld)a);
    ans += need;

    int start = x[i];
    int end = upper_bound(all(x), start + 2LL * d) - x.begin();

    bit.add(i + 1, end + 1, a * need);
  }
  cout << ans << endl;
}