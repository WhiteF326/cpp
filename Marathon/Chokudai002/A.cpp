#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

bool isPrime(int num){
	bool ans = true;
	if(num < 2) return false;
	else if (num == 2) return true;
	else{
		for(int i = 2; i <= (int)sqrt(num); i++){
			if(num % i == 0){
				ans = false;
			}
		}
	}
	return ans;
}
 
int nextPrime(int d){
	int ans = d;
	while(true){
		ans++;
		if(isPrime(ans)) break;
	}
	return ans;
}

ll modpow(ll x, ll n, int mod){
  ll ret = 1;
  if(mod == 0){
    while(n > 0){
      if(n & 1) ret *= x;
      x *= x;
      n >>= 1;
    }
  }else{
    while(n > 0){
      if(n & 1) ret = ret * x % mod;
      x = x * x % mod;
      n >>= 1;
    }
  }
  return ret;
}

int main(){
  // clock() - ti < 999 * CLOCKS_PER_SEC / 100
  int ti = clock();
  ll p = 2;
  
  for(int i = 0; i < 100; i++){
    cout << fixed << modpow(p, floor(log(1000000000) / log(p)), 0) << endl;
    p = nextPrime(p);
  }
}