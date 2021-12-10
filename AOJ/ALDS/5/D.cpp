#include <bits/stdc++.h>
using namespace std;

#define ll long long

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
  int n; cin >> n;

  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];

  // 座圧
  vector<int> b(a.begin(), a.end());
  sort(a.begin(), a.end());
  vector<int> pos(n);
  for(int i = 0; i < n; i++){
    pos[i] = (lower_bound(a.begin(), a.end(), b[i]) - a.begin()) + 1;
  }

  BIT<ll> bit(n + 1);
  ll ans = 0;
  for(int i = 0; i < n; i++){
    ans += i - bit.sum(pos[i]);
    bit.add(pos[i], pos[i] + 1, 1);
  }

  cout << ans << endl;
}