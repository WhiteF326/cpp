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
#define pii pair<int, int>
#define minf -100000000
#define chmax(a, b) a = max(a, b)


int main(){
  int h, w; cin >> h >> w;
  vector<vector<int>> stg(h, vector<int>(w, 0));
  for(int i = 0; i < h; i++){
    string s; cin >> s;
    for(int j = 0; j < w; j++){
      stg[i][j] = s[j] == '-' ? -1 : 1;
    }
  }

  vector<vector<pii>> sc(h, vector<pii>(w, {minf, minf}));
  sc[0][0] = {0, 0};
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      // 下へ更新
      if((i + j) % 2){
        // Aoki
        if(i + 1 < h){
          chmax(sc[i + 1][j].first, sc[i][j].first);
          chmax(sc[i + 1][j].second, sc[i][j].second + stg[i + 1][j]);
        }
        if(j + 1 < w){
          chmax(sc[i][j + 1].first, sc[i][j].first);
          chmax(sc[i][j + 1].second, sc[i][j].second + stg[i][j + 1]);
        }
      }else{
        // Takahashi
        if(i + 1 < h){
          chmax(sc[i + 1][j].first, sc[i][j].first + stg[i + 1][j]);
          chmax(sc[i + 1][j].second, sc[i][j].second);
        }
        if(j + 1 < w){
          chmax(sc[i][j + 1].first, sc[i][j].first + stg[i][j + 1]);
          chmax(sc[i][j + 1].second, sc[i][j].second);
        }
      }
    }
  }

  if(sc[h - 1][w - 1].first > sc[h - 1][w - 1].second){
    cout << "Takahashi" << endl;
  }else if(sc[h - 1][w - 1].first < sc[h - 1][w - 1].second){
    cout << "Aoki" << endl;
  }else{
    cout << "Draw" << endl;
  }
}