#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
using ll = long long;
using ld = long double;

constexpr int modv = 1000000007;

int main(){
  int n; cin >> n;
  ll ans = 1;
  for(int i = 0; i < n; i++){
    ll res = 0;
    for(int j = 0; j < 6; j++){
      ll x; cin >> x;
      res = (res + x) % modv;
    }
    ans = (ans * res) % modv;
  }
  cout << ans << endl;
}