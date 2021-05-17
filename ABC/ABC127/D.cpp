#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  ll n, m; cin >> n >> m;
  map<ll, ll, greater<ll>> alist;

  for(int i = 0; i < n; i++){
    ll a; cin >> a;
    alist[a]++;
  }
  for(int i = 0; i < m; i++){
    ll b, c; cin >> b >> c;
    alist[c] += b;
  }

  ll ans = 0;
  for(auto itr = alist.begin(); itr != alist.end(); itr++){
    ans += itr->first * min(itr->second, n);
    n -= itr->second;
    if(n <= 0) break;
  }

  cout << ans << endl;
}