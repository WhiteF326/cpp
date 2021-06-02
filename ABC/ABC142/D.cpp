#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j)
using ll = long long;
using ld = long double;

bool IsPrime(ll num){
	bool ans = true;
	if(num < 2) return false;
	else if (num == 2) return true;
	else{
		for(ll i = 2; i <= (ll)sqrt(num); i++){
			if(num % i == 0){
				ans = false;
			}
		}
	}
	return ans;
}

map<ll, int> enumpr(ll n) {
  map<ll, int> V;
  for (ll i = 2; i*i <= n; i++) while (n%i == 0) V[i]++, n /= i;
  if (n > 1) V[n]++;
  return V;
}

int main(){
  // 10^6までなので公約数を列挙する
  ll a, b; cin >> a >> b;
  cout << enumpr((ll)gcd(a, b)).size() + 1 << endl;
}