#include <bits/stdc++.h>
using namespace std;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define const constexpr
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;
#define query(t) for(int _ = 0; _ < t; _++)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


ll gcd(ll x, ll y){
  while(y > 0){
    ll r = x % y;
    x = y;
    y = r;
  }
  return x;
}

int main(){
  int t; cin >> t;
  query(t){
    int n; cin >> n;
    vector<ll> v(n);
    aryin(v, n);

    ll a = v[0], b = v[1];
    for(int i = 2; i < n; i++){
      if(i % 2) b = gcd(b, v[i]);
      else a = gcd(a, v[i]);
    }
    vector<ll> test = {a, b};

    bool found = false;
    for(int i = 0; i < 2; i++){
      ll ch = test[i];
      bool ans = true;
      for(int j = 0; j < n - 1; j++){
        if(v[j] % ch == 0 && v[j + 1] % ch == 0) ans = false;
        if(v[j] % ch != 0 && v[j + 1] % ch != 0) ans = false;
      }
      if(ans){
        cout << ch << endl;
        found = true;
        break;
      }
    }
    if(!found) cout << 0 << endl;
  }
}