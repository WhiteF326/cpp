#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define const constexpr
using ll = long long;
using ld = long double;

const ll modv = 1000000007;

int main(){
  int n; cin >> n;
  vector<vector<int>> h(n), l(n);

  for(int i = 0; i < n; i++){
    int a; cin >> a;
    for(int j = 0; j < a; j++){
      int x, y; cin >> x >> y;
      if(y == 0) l[i].push_back(x - 1);
      else h[i].push_back(x - 1);
    }
  }

  int ans = 0;
  for(int m = 0; m < (1 << n); m++){
    bool flg = true;
    int t = 0;
    for(int i = 0; i < n; i++){
      if(m & (1 << i)){
        t++;
        for(auto hs : h[i]) if(!(m & (1 << hs))) flg = false;
        for(auto ls : l[i]) if(m & (1 << ls)) flg = false;
      }
    }
    if(flg) ans = max(ans, t);
  }
  cout << ans << endl;
}