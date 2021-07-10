#include <bits/stdc++.h>
using namespace std;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  ll n; cin >> n;
  int ans = 0;
  for(ll i = 1; i < 200000; i++){
    ll j = n * n - i * i;
    for(ll x = 1; x <= sqrt(j); x++){
      if(x * x == j){
        ans++;
      }
    }
  }
  cout << ans << endl;
}