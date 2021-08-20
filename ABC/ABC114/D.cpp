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

struct fastComb{
  vector<ll> f;
  ll modv;
  int size;

  fastComb(int size, ll modv, bool checkmodv){
    if(checkmodv){
      bool ans = true;
      if(modv < 2) ans = false;
      else if (modv == 2) ans = true;
      else{
        for(int i = 2; i <= (int)sqrt(modv); i++){
          if(modv % i == 0){
              ans = false;
          }
        }
      }
      assert(ans);
    }

    f.resize(size + 1);
    this->modv = modv;
    this->size = size;
    f[0] = 1;
    for(int i = 1; i < this->size + 1; i++) f[i] = (f[i - 1] * i) % this->modv;
  }

  ll inv(ll x){
    ll res = 1, k = modv - 2, y = x;
    while(k){
      if(k & 1) res = (res * y) % modv;
      y = y * y % modv;
      k /= 2;
    }
    return res;
  }

  ll C(int n, int r){
    assert(r <= n);
    assert(n <= this->size);
    assert(r <= this->size);

    ll a = f[n];
    ll b = f[n - r];
    ll c = f[r];
  
    ll bc = (b * c) % modv;
  
    return (a * inv(bc)) % modv;
  }
};

int main(){
  int n; cin >> n;
  vector<int> prms(101, 0);

  for(int i = 1; i <= n; i++){
    int p = i;
    for(int j = 2; j * j <= p; j++){
      while(p % j == 0) prms[j]++, p /= j;
      if(p > 1) prms[p]++;
    }
  }

  int ans = 0;
  // {75} {3, 25} {15, 5} {3, 5, 5}
  for(int i = 2; i <= n; i++){
    if(prms[i] >= 74) ans++;
  }
  for(int i = 2; i <= n; i++){
    for(int j = i + 1; j <= n; j++){
      if(prms[i] >= 2 && prms[j] >= 24 && i != j) ans++;
    }
  }
  for(int i = 2; i <= n; i++){
    for(int j = 0; j <= n; j++){
      if(prms[i] >= 4 && prms[j] >= 14 && i != j) ans++;
    }
  }
  for(int i = 2; i <= n; i++){
    for(int j = 2; j <= n; j++){
      for(int k = j + 1; k <= n; k++){
        if(prms[i] >= 2 && prms[j] >= 4 && prms[k] >= 4 && i != j && i != k) ans++;
      }
    }
  }
  cout << ans << endl;
}