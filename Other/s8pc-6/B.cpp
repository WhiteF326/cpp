#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
using ll = long long;
using ld = long double;

int main(){
  ll n; cin >> n;
  vector<ll> a(n), b(n);
  for(int i = 0; i < n; i++){
    cin >> a[i] >> b[i];
  }
  ll ans = LLONG_MAX;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      ll start = a[i], goal = b[j];
      ll res = 0;
      for(int k = 0; k < n; k++){
        res += abs(a[k] - start) + abs(a[k] - b[k]) + abs(b[k] - goal);
      }
      ans = min(ans, res);
    }
  }
  cout << ans << endl;
}