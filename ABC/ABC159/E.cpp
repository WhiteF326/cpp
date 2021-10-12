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
  int h, w, k; cin >> h >> w >> k;
  vector<vector<int>> sr(h, vector<int>(w));
  for(int i = 0; i < h; i++){
    string s; cin >> s;
    for(int j = 0; j < w; j++){
      sr[i][j] = s[j] == '1';
    }
  }

  int l = 0, r = h * w, m;
  while(r >= l){
    m = l + (r - l) / 2;
    // m 回で分けられるか？
    bool divide = false;
    for(int i = 0; i < (1 << (h - 1)); i++){
      vector<vector<int>> pls(1, vector<int>(1, 0));
      for(int j = 0; j < h - 1; j++){
        if(i & (1 << j)){
          pls.emplace_back(vector<int>(1, j + 1));
        }else{
          pls[pls.size() - 1].emplace_back(j + 1);
        }
      }
      // 超過
      if(m - pls.size() + 1 < 0) continue;
      // 区間の計算
      bool flg = false;
      vector<pair<int, int>> ranges;
      for(auto px : pls){
        int left = 0, sum = 0;
        for(int j = 0; j < w; j++){
          for(int v : px) sum += sr[v][j];
          if(sum == 0){
            left++;
          }
          if(sum >= k){
            if(left == j){
              flg = true;
              break;
            }else{
              ranges.push_back(mp(left, j));
              left = j + 1;
              sum %= k;
            }
          }
          if(flg) break;
        }
        if(flg) break;
      }
      if(!flg){
        // 区間スケジューリング
        sort(all(ranges), greater<pair<int, int>>());
        int res = 0, pt = INT_MAX;
        for(int j = 0; j < ranges.size(); j++){
          if(pt >= ranges[j].second){
            res++;
            pt = ranges[j].first;
          }
        }
        if(pls.size() - 1 + res <= m){
          divide = true;
          break;
        }
      }
    }
    if(divide){
      r = m - 1;
    }else{
      l = m + 1;
    }
  }
  cout << m << endl;
}