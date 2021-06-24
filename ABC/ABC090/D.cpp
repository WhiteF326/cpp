#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  ll n, k; cin >> n >> k;
  if(k == 0) cout << n * n << endl;
  else{
    ll ans = 0;
    for(int b = k + 1; b <= n; b++){
      ll c = n / b;
      
    }
    cout << ans << endl;
  }
}