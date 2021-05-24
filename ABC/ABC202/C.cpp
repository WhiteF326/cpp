#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  int n; cin >> n;
  vector<int> a(n), b(n), c(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < n; i++) cin >> b[i];
  for(int i = 0; i < n; i++) cin >> c[i];
  map<int, ll> capp;
  for(int i = 0; i < n; i++) capp[c[i]]++;
  vector<pair<int, ll>> blist(n);
  for(int i = 0; i < n; i++){
    blist[i] = make_pair(b[i], capp[i + 1]);
  }
  map<int, ll> bapp;
  for(int i = 0; i < n; i++){
    bapp[blist[i].first] += blist[i].second;
  }
  ll ans = 0;
  for(int i = 0; i < n; i++){
    ans += bapp[a[i]];
  }
  cout << ans << endl;
}