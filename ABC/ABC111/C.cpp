#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
using ll = long long;
using ld = long double;

ll gcd(ll x,ll y){
  if(x < y) swap(x, y);
  ll r;
  while(y > 0){
    r = x % y;
    x = y;
    y = r;
  }
  return x;
}

int main(){
  int n; cin >> n;
	ll ans; cin >> ans;
	for(int i = 0; i < n - 1; i++){
		ll a; cin >> a;
		ans = gcd(a, ans);
	}
	cout << ans << endl;
}