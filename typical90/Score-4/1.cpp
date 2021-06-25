#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
using ll = long long;
using ld = long double;

int main(){
  int n, l; cin >> n >> l;
  int k; cin >> k;
  vector<ll> a(n + 2, 0);
  for(int i = 0; i < n; i++) cin >> a[i + 1];
  a[n + 1] = l;
  vector<ll> dist(n + 1);
  for(int i = 0; i < n + 1; i++) dist[i] = a[i + 1] - a[i];

  int ans = 0;

  int m = 0, x = l / (k + 1);
  while(m <= x){
    int t = (m + x) / 2;
    // cout << m << " " << t << " " << x << endl;
    ll f = 0, res = 0;
    for(int i = 0; i < n + 1; i++){
      res += dist[i];
      if(res >= t){
        f++;
        res = 0;
      }
    }
    
    if(res >= t) f++;
    if(f >= k + 1){
      ans = max(t, ans);
      m = t + 1;
    }else{
      x = t - 1;
    }
  }
  cout << ans << endl;
}