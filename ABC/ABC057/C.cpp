#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
using ll = long long;
using ld = long double;

int main(){
  ll n; cin >> n;
  ll ans = INT_MAX;
  for(ll i = 1; i <= sqrt(n); i++){
    if(n % i == 0){
      ll b = n / i;
      ans = min(ans, (ll)ceil(log10(b + 1)));
    }
  }
  cout << ans << endl;
}