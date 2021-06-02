#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
using ll = long long;
using ld = long double;

int main(){
  int n, m; cin >> n >> m;
  priority_queue<ll> a;
  for(int i = 0; i < n; i++){
    ll x; cin >> x;
    a.push(x);
  }

  for(int i = 0; i < m; i++){
    ll x = a.top();
    a.pop();
    a.push(x / 2);
  }

  ll ans = 0;

  for(int i = 0; i < n; i++){
    ans += a.top();
    a.pop();
  }

  cout << ans << endl;
}