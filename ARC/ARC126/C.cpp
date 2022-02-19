#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)


ll gcd(ll x, ll y){
  while(y > 0){
    ll r = x % y;
    x = y;
    y = r;
  }
  return x;
}
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n; cin >> n;
  ll k; cin >> k;
  vector<int> a(n);
  aryin(a, n);

  ll left = a[0];
  for(int i = 1; i < n; i++){
    left = gcd(left, a[i]);
  }
  ll right = 1LL << 61;
  while(right - left > 1){
    ll mid = left + (right - left) / 2LL;

    ll res = 0;
    for(int i = 0; i < n; i++){
      ll rv = a[i] % mid;
      if(rv) res += mid - rv;
    }

    // cout << mid << " " << res << endl;
    
    if(res > k){
      right = mid;
    }else{
      left = mid;
    }
  }

  cout << left << endl;
}
