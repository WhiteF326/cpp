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
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  ifstream ifs("in20.txt");

  int n; ifs >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) ifs >> a[i];

  auto ctr = [](ll p, ll t){
    p++;
    ll l = 0, r = ceil(pow(modpow(10, 18, 0), (ld)1 / t));

    while(r - l > 1) {
      ll m = l + (r - l) / 2;

      if(modpow(m, t, 0) >= p){
        r = m;
      }else{
        l = m;
      }
    }

    return r;
  };

  ll mx = 1;
  ll cur = 0;
  for(int i = 1; i < n; i++){
    if(a[i] > a[i - 1]){
      // 文字数が増える
      cur *= modpow(ctr(cur, a[i - 1]), a[i] - a[i - 1], 0);
    }else if(a[i] == a[i - 1]){
      // 文字数はそのまま
      cur++;
    }else{
      // 文字数が減る
      cur /= modpow(ctr(cur, a[i]), a[i - 1] - a[i], 0);
      cur++;
    }
    // cout << cur << " ";
    // cout << ctr(cur, a[i]) << endl;
    mx = max(mx, ctr(cur, a[i]));
  }
  
  cout << mx << endl;
}