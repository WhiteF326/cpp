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

int main(){
  ll n; cin >> n;

  ll divrem = 1, ans = 0;
  while(divrem < sqrt(n)){
    if((n - divrem) % divrem == 0){
      ll p = (n - divrem) / divrem;
      for(ll x = max(1LL, p - 1); x <= p + 1; x++){
        if(n / x == n % x) ans += x;
      }
    }
    divrem++;
  }
  cout << ans << endl;
}