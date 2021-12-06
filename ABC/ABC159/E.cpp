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

  int ans = INT_MAX;

  for(int i = 0; i < (1 << (h - 1)); i++){
    vector<vector<int>> pls(1, vector<int>(1, 0));
    for(int j = 0; j < h - 1; j++){
      if(i & (1 << j)){
        pls.emplace_back(vector<int>(1, j + 1));
      }else{
        pls[pls.size() - 1].emplace_back(j + 1);
      }
    }
    int ps = pls.size();
    // 貪欲
    bool flg = true;
    int res = 0;
    vector<int> psuml(ps, 0);
    for(int j = 0; j < w; j++){
      vector<int> aps(ps, 0);
      for(int x = 0; x < ps; x++){
        for(int v : pls[x]) aps[x] += sr[v][j];
      }
      // 一列で超えてしまう
      if(*max_element(all(aps)) > k){
        flg = false;
        break;
      }
      bool cut = false;
      for(int x = 0; x < ps; x++){
        if(aps[x] + psuml[x] > k) cut = true;
      }
      if(!cut){
        for(int x = 0; x < ps; x++) psuml[x] += aps[x];
      }else{
        res++;
        for(int x = 0; x < ps; x++) psuml[x] = aps[x];
      }
    }
    if(flg){
      ans = min(ans, res + ps - 1);
    }
  }
  cout << ans << endl;
}