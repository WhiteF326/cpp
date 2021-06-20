#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  ll n; cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  map<int, ll> app;
  for(int i = 0; i < n; i++) app[a[i]]++;

  ll ans = (n - 1) * n / 2;
  for(auto itr = app.begin(); itr != app.end(); itr++){
    ans -= (itr->second - 1) * itr->second / 2;
  }
  cout << ans << endl;
}