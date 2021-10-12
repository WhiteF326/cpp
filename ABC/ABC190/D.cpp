#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
 
#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define const constexpr
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;

const ll modv = 1000000007;

int main(){
  ll n; cin >> n;

  int ans = 0;
  n *= 2LL;
  
  while(n % 2 == 0) n /= 2;
  ll sqr = sqrt(n);
  for(int i = 1; i <= sqr; i++){
    if(n % i == 0) ans++;
  }

  cout << (ans * 2 - (sqr * sqr == n)) * 2 << endl;
}