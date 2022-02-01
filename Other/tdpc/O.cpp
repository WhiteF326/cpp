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
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


struct Comb {
  vector<vector<ll>> com;
  ll p;
  Comb(ll _p) : p(_p) {
    init(p);
  }

  void init(ll p) {
    com.assign(p, vector<ll>(p));
    com[0][0] = 1;
    for (int i = 1; i < p; i++) {
      com[i][0] = 1;
      for (int j = i; j > 0; j--) {
        com[i][j] = (com[i - 1][j - 1] + com[i - 1][j]) % p;
      }
    }
  }

  ll C(ll n, ll k) {
    ll ret = 1;
    while(n > 0){
      int ni = n % p;
      int ki = k % p;
      ret *= com[ni][ki];
      ret %= p;
      n /= p;
      k /= p;
    }
    return ret;
  }
};
const ll modv = 1000000007;

int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  vector<int> freq(26, 0);
  aryin(freq, 26);

  // i 種類目、隣り合う文字が同じ箇所が j
  
}