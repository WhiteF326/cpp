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

const ll modv = 1000000007;

int main(){
  int h, w; cin >> h >> w;
  vector<vector<bool>> stage(h, vector<bool>(w));
  vector<vector<int>> vl(w, vector<int>(1, -1)), hl(h, vector<int>(1, -1));
  for(int i = 0; i < h; i++){
    string s; cin >> s;
    for(int j = 0; j < w; j++){
      if(s[j] == '#'){
        vl[j].push_back(i);
        hl[i].push_back(j);
        stage[i][j] = false;
      }else stage[i][j] = true;
    }
  }
  for(int i = 0; i < h; i++){
    hl[i].push_back(w);
  }
  for(int j = 0; j < w; j++){
    vl[j].push_back(h);
  }
  for(int i = 0; i < h; i++){
    for(int v : hl[i]) cout << v << " ";
    cout << endl;
  }
  int ans = 0;
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      if(stage[i][j]){
        int res = 0;
        int hpos = lower_bound(all(hl[i]), j) - hl[i].begin();
        res += hl[i][hpos + 1] - hl[i][hpos] - 1;
        int vpos = lower_bound(all(vl[j]), i) - vl[j].begin();
        res += vl[j][vpos + 1] - vl[j][vpos] - 1;
        ans = max(ans, res);
        cout << i << " " << j << " " << res << endl;
      }
    }
  }
  cout << ans << endl;
}