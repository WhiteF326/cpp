#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
using ll = long long;
using ld = long double;

ll expow(ll x, ll n){
  ll ret = 1;
  while(n > 0){
    if(n & 1) ret *= x;
    x *= x;
    n >>= 1;
  }
  return ret;
}

int main(){
  ll n; cin >> n;
  string ans = "";
  string s = "abcdefghijklmnopqrstuvwxyz";
  while(n){
    n--;
    ans += s.substr(n % 26, 1);
    n /= 26;
  }
  reverse(ans.begin(), ans.end());
  cout << ans << endl;
}