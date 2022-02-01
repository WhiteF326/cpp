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


constexpr int primes[15] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
ll gcd(ll x, ll y){
  while(y > 0){
    ll r = x % y;
    x = y;
    y = r;
  }
  return x;
}
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n; cin >> n;
  vector<ll> x(n);
  for(int i = 0; i < n; i++) cin >> x[i];
 
  ll ans = 1;
  for(int i : primes) ans *= i;
 
  for(int i = 0; i < (1 << 15); i++){
    ll res = 1;
    for(int j = 0; j < 15; j++){
      if(i & (1 << j)) res *= primes[j];
    }
    bool flg = true;
    for(int j = 0; j < n; j++){
      if(gcd(res, x[j]) == 1){
        flg = false;
        break;
      }
    }
    if(flg){
      ans = min(ans, res);
    }
  }
  cout << ans << endl;
}