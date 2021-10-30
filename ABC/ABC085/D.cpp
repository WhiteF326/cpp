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
  int n, h; cin >> n >> h;
  vector<pair<int, int>> sw(n);

  int smax = 0;

  for(int i = 0; i < n; i++){
    cin >> sw[i].first >> sw[i].second;
    smax = max(smax, sw[i].first);
  }

  sort(all(sw), [&](pair<int, int> a, pair<int, int> b){
    return b.second < a.second;
  });
  int ans = 0;
  for(int i = 0; i < n; i++){
    if(sw[i].second > smax){
      h -= sw[i].second;
      ans++;
      if(h <= 0){
        cout << ans << endl;
        return 0;
      }
    }else{
      break;
    }
  }

  ans += ceil(h / (double)smax);

  cout << ans << endl;
}