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
const ll modv = 1000000007;

int main(){
  int n; cin >> n;
  map<int, int> mx;
  for(int i = 0; i < n; i++){
    int a; cin >> a;
    mx[a]++;
  }

  if(n % 2){
    if(mx[0] != 1){
      cout << 0 << endl;
    }else{
      int start = 2;
      for(int i = start; i <= n; i += 2){
        if(mx[i] != 2){
          cout << 0 << endl;
          return 0;
        }
      }

      cout << modpow(2, n / 2, modv) << endl;
    }
  }else{
    int start = 1;
    for(int i = start; i <= n; i += 2){
      if(mx[i] != 2){
        cout << 0 << endl;
        return 0;
      }
    }

    cout << modpow(2, n / 2, modv) << endl;
  }
}