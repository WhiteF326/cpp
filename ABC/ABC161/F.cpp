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
#define query(t) for(int _ = 0; _ < t; _++)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


int main(){
  ll n; cin >> n;
  if(n == 2){
    cout << 1 << endl;
    return 0;
  }
  set<ll> s;

  s.insert(n);
  s.insert(n - 1);

  ll m = n - 1;

  for(ll i = 2; i * i <= m; i++){
    if(m % i == 0){
      s.insert(i);
      s.insert(m / i);
    }
  }

  for(ll i = 2; i * i <= n; i++){
    if(n % i == 0){
      // i
      ll sl = n;
      while(sl % i == 0) sl /= i;
      if(sl % i == 1) s.insert(i);
      // n / i
      ll sr = n, r = n / i;
      while(sr % r == 0) sr /= r;
      if(sr % r == 1) s.insert(n / i);
    }
  }

  cout << s.size() << endl;
}