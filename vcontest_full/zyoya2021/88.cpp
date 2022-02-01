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
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n, h; cin >> n >> h;
  vector<pair<int, int>> sw(n);
 
  int sx = 0;
 
  for(int i = 0; i < n; i++){
    cin >> sw[i].first >> sw[i].second;
    sx = max(sx, sw[i].first);
  }
 
  sort(all(sw), [&](pair<int, int> a, pair<int, int> b){
    return b.second < a.second;
  });
  int ans = 0;
  for(int i = 0; i < n; i++){
    if(sw[i].second > sx){
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
 
  cout << (ll)(ans + ceil(h / (double)sx)) << endl;
}