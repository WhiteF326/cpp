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
  int n; cin >> n;
  vector<ld> l(n), al(n);
  for(int i = 0; i < n; i++){
    ld a, b; cin >> a >> b;
    l[i] = a / b;
    al[i] = a;
  }
  ld t = accumulate(all(l), (ld)0);
  t /= 2.0;

  ld ans = 0;
  for(int i = 0; i < n; i++){
    if(l[i] < t){
      t -= l[i];
      ans += al[i];
    }else{
      ans += al[i] * (t / l[i]);
      cout << fs(12) << ans << endl;
      return 0;
    }
  }
}