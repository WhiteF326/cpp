#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
using ll = long long;
using ld = long double;

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
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];

  if(n % 3){
    if(accumulate(a.begin(), a.end(), 0)) cout << "No" << endl;
    else cout << "Yes" << endl;
  }else{
    map<int, int> s;
    for(int i = 0; i < n; i++) s[a[i]]++;
    int t = 0;
    bool ans = true;
    switch(s.size()){
      case 1:
        if(s[0] == n) cout << "Yes" << endl;
        else cout << "No" << endl;
        break;
      
      case 2:
        if(s[0] == n / 3) cout << "Yes" << endl;
        else cout << "No" << endl;
        break;
      
      case 3:
        for(auto itr = s.begin(); itr != s.end(); itr++){
          t = t ^ itr->first;
          if(itr->second != n / 3) ans = false;
        }
        if(t != 0) ans = false;
        cout << (ans ? "Yes" : "No") << endl;
        break;
      
      default:
        cout << "No" << endl;
        break;
    }
  }
}