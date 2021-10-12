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
  string s; cin >> s;

  vector<ll> rr(n, 0), rg(n, 0), rb(n, 0);
  rr[0] = count(all(s), 'R');
  rg[0] = count(all(s), 'G');
  rb[0] = count(all(s), 'B');
  for(int i = 1; i < n; i++){
    rr[i] = rr[i - 1];
    rg[i] = rg[i - 1];
    rb[i] = rb[i - 1];
    if(s[i - 1] == 'R') rr[i]--;
    if(s[i - 1] == 'G') rg[i]--;
    if(s[i - 1] == 'B') rb[i]--;
  }

  ll ans = 0;
  string x = "RGB";
  for(int i = 0; i < n - 2; i++){
    for(int j = i + 1; j < n - 1; j++){
      if(s[i] == s[j]) continue;

      int vd = 2 * j - i;
      
      vector<bool> choose(3, true);
      for(int v = 0; v < 3; v++){
        if(s[i] == x[v]) choose[v] = false;
        if(s[j] == x[v]) choose[v] = false;
      }
      if(choose[0]){
        ans += rr[j + 1];
        if(vd < n){
          if(s[vd] == 'R') ans--;
        }
      }
      if(choose[1]){
        ans += rg[j + 1];
        if(vd < n){
          if(s[vd] == 'G') ans--;
        }
      }
      if(choose[2]){
        ans += rb[j + 1];
        if(vd < n){
          if(s[vd] == 'B') ans--;
        }
      }
    }
  }

  cout << ans << endl;
}