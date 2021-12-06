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
  ll x, y; cin >> x >> y;
  if(x > y){
    cout << x - y << endl;
    return 0;
  }

  ll ans = y;
  ll dy = y, act = 0;
  while(dy > 0){
    ans = min(ans, abs(dy - x) + act);
    act += 1;
    act += dy % 2;
    dy /= 2;
  }

  cout << ans << endl;
}