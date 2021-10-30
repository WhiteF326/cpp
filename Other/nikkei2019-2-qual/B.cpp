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

ll modpow(ll x, ll n, int mod){
  ll ret = 1;
  if(mod == 0){
    while(n > 0){
      if(n & 1) ret *= x;
      x *= x;
      n >>= 1;
    }
  }else{
    while(n > 0){
      if(n & 1) ret = ret * x % mod;
      x = x * x % mod;
      n >>= 1;
    }
  }
  return ret;
}


int main(){
  int n; cin >> n;
  vector<int> d(n); aryin(d, n);
  map<int, int> cnt;
  for(int i : d) cnt[i]++;
  int end = *max_element(all(d));
  if(cnt[0] != 1 || d[0] != 0){
    cout << 0 << endl;
  }else{
    vector<int> dp(n, 0);
    dp[0] = 1;
    for(int i = 1; i < n; i++){
      dp[i] = (dp[i - 1] * modpow(cnt[i - 1], cnt[i], modv)) % modv;
    }
    cout << dp[end] << endl;
  }
}