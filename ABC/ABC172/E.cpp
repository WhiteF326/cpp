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


const int MAX = 510000;
const int MOD = 1000000007;

// combination
long long fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; i++){
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}

long long C(int n, int k){
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

// permutation
ll P(int n, int k){
  return (C(n, k) * fac[k]) % MOD;
}

int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n, m; cin >> n >> m;
  COMinit();

  ll res = P(m, n);

  ll ans = P(m, n);
  for(int i = 1; i <= n; i++){
    if(i % 2){
      ans = (ans - (C(n, i) * P(m - i, n - i) % MOD)) % MOD;
    }else{
      ans = (ans + (C(n, i) * P(m - i, n - i) % MOD) + MOD) % MOD;
    }
    // cout << ans << endl;
  }

  cout << (ans * res) % MOD << endl;
}