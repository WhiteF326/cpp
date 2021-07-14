#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

ll modv = 1000000007;

int main(){
  int n; cin >> n;
  vector<ll> c(n);
  for(int i = 0; i < n; i++) cin >> c[i];
  
  sort(c.begin(), c.end());
  ll ans = 1;

  for(int i = 0; i < n; i++){
    ans *= (c[i] - i);
    ans %= modv;
  }
  cout << ans << endl;
}