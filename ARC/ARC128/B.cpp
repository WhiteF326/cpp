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
  int t; cin >> t;
  query(t){
    ll ans = LLONG_MAX;
    vector<ll> c(3); aryin(c, 3);
    for(int i = 0; i < 3; i++){
      if(c[(i + 1) % 3] % 3 == c[(i + 2) % 3] % 3){
        ans = min(ans, max(c[(i + 1) % 3], c[(i + 2) % 3]));
      }
    }
    if(ans == LLONG_MAX){
      cout << -1 << endl;
    }else{
      cout << ans << endl;
    }
  }
}