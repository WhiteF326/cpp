#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
using ll = long long;
using ld = long double;

ll sc(string s){
  vector<ll> cnt(10);
  for(int i = 0; i < 10; i++) cnt[i] = i;
  for(char c : s) cnt[c - '0'] *= 10;
  return accumulate(cnt.begin(), cnt.end(), 0);
}

int main(){
  int k; cin >> k;
  string s, t; cin >> s >> t;

  vector<ll> c(10, k);
  for(char x : s + t) c[x - '0']--;
  ll w = 0;
  for(ll x = 1; x <= 9; x++){
    for(ll y = 1; y <= 9; y++){
      s.back() = '0' + x;
      t.back() = '0' + y;
      if(sc(s) <= sc(t)) continue;
      w += c[x] * (c[y] - (x == y));
    }
  }
  ll r = 9 * k - 8;
  cout << fs(12) << (double)w / r / (r - 1) << endl;
}