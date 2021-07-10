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
    ll j = pow(floor(sqrt(pow(n, 2) - pow(i, 2))), 2);
    if(j && j == pow(n, 2) - pow(i, 2)) ans++;
  }
  cout << ans << endl;
}