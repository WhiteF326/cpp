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


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  ll n; cin >> n;

  ll l = 0, r = 20000000000LL;
  while(r - l > 1){
    ll m = l + (r - l) / 2;
    if(m * (m + 1) / 2 <= n + 1){
      l = m;
    }else{
      r = m;
    }
  }
  cout << n - l + 1 << endl;
}