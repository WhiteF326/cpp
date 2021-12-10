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


const ll modv = 998244353;

class smart_sieve {
  intmax_t L, R, M;
  std::vector<int> small;  // 小さい篩
  std::vector<std::vector<intmax_t>> large;  // 大きい篩
  std::vector<intmax_t> aux;  // aux[i] := large[i] の素因数の積

public:
  smart_sieve(intmax_t L, intmax_t R): L(L), R(R), M(sqrt(R)+1) {
    small.resize(M);
    std::iota(small.begin(), small.end(), 0);
    large.resize(R-L);
    aux.assign(R-L, 1);

    for (intmax_t i = 2; i*i < R; ++i) {
      if (small[i] < i) continue;
      small[i] = i;
      for (intmax_t j = i*i; j < M; j += i)
        if (small[j] == j) small[j] = i;

      for (intmax_t j = (L+i-1)/i*i; j < R; j += i) {
        intmax_t k = j;
        do {
          // aux[j-L] > M で判定した方がいいかも？
          // j / aux[j-L] < M の方がいい？（割り算したくない）
          if (aux[j-L] * aux[j-L] > R) break;

          large[j-L].push_back(i);
          aux[j-L] *= i;
          k /= i;
        } while (k % i == 0);
      }
    }
  }

  std::vector<intmax_t> factor(intmax_t n) {
    assert(L <= n && n < R);
    std::vector<intmax_t> res = large[n-L];
    n /= aux[n-L];
    if (n >= M) {
      // この場合，n は素数となることが示せる（はず）
      // n*n >= R だとオーバーフローしそう？
      res.push_back(n);
      return res;
    }
    while (n > 1) {
      res.push_back(small[n]);
      n /= small[n];
    }
    return res;
  }
};

int main(){
  ll n; cin >> n;
  int k; cin >> k;

  map<ll, int> lx;

  ll start = n - (ll)k + 1;
  smart_sieve ss(start, n + 1);

  for(ll i = start; i <= n; i++){
    auto f = ss.factor(i);
    for(auto v : f) lx[v]++;
  }

  vector<int> spf(k + 1, 0);
  spf[1] = 1;
  for(int i = 2; i <= k; i++){
    if(spf[i]) continue;
    for(int j = i; j <= k; j += i){
      spf[j] = i;
    }
  }

  for(int i = 1; i <= k; i++){
    int cur = i;
    while(spf[cur] != 1){
      lx[spf[cur]]--;
      cur /= spf[cur];
    }
  }

  ll ans = 1;
  for(auto p : lx){
    ans = (ans * (p.second + 1)) % modv;
  }
  cout << ans << endl;
}