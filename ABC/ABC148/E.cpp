#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j)
using ll = long long;
using ld = long double;

int main(){
  ll n; cin >> n;
  if(n % 2){
    cout << 0 << endl;
  }else{
    n /= 10;
    ll ans = n;
    ll p = 5;
    while(p <= n){
      ans += n / p;
      p *= 5;
    }
    cout << ans << endl;
  }
}