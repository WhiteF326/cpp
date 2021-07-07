#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j)
using ll = long long;
using ld = long double;

ll modv = 1000000007;
vector<ll> f(1000001);

ll inv(ll x){
  ll res = 1, k = modv - 2, y = x;
  while(k){
    if(k & 1) res = (res * y) % modv;
    y = y * y % modv;
    k /= 2;
  }
  return res;
}

ll C(int n, int k){
  ll a = f[n];
  ll b = f[n - k];
  ll c = f[k];

  ll bc = (b * c) % modv;

  return (a * inv(bc)) % modv;
}

int main(){
  f[0] = 1;
  for(int i = 1; i < 1000001; i++) f[i] = (f[i - 1] * i) % modv;

  int x, y; cin >> x >> y;
  if((x + y) % 3){
    cout << 0 << endl;
  }else{
    int step = (x + y) / 3;
    if(x > y) swap(y, x);
    if(x < step){
      cout << 0 << endl;
    }else{
      cout << C((x + y) / 3, x - step) << endl;
    }
  }
}