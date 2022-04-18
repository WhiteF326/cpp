#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)


#define mint modint998244353

#define mtrx vector<vector<mint>>
mtrx mtrxMul(mtrx &a, mtrx &b) {
  mtrx res(a.size(), vector<mint>(b[0].size()));
  for(int i = 0; i < a.size(); i++){
    for(int j = 0; j < b[0].size(); j++){
      for(int k = 0; k < b.size(); k++){
        res[i][j] += a[i][k] * b[k][j];
      }
    }
  }
  return res;
}
mtrx mtrxPow(mtrx a, ll n){
  mtrx res(a.size(), vector<mint>(a.size()));
  for(int i = 0; i < a.size(); i++){
    res[i][i] = 1;
  }
  while(n > 0){
    if(n & 1) res = mtrxMul(a, res);
    a = mtrxMul(a, a);
    n >>= 1;
  }
  return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll n; cin >> n;

    mtrx base(11, vector<mint>(1, 0));
    for(int i = 0; i < n; i++){
        base[i + 1][0] = 1;
    }

    mtrx pw(11, vector<mint>(11, 0));
    for(int i = 1; i <= 9; i++){
        for(int j = i - 1; j <= i + 1; j++){
            pw[i][j] = 1;
        }
    }

    pw = mtrxPow(pw, n);
    mtrx res = mtrxMul(pw, base);
    
}