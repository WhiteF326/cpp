#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;
  vector<vector<pair<int, int>>> d(n, vector<pair<int, int>>(0));
  for(int i = 0; i < n; i++){
    int a; cin >> a;
    for(int j = 0; j < a; j++){
      int x, y; cin >> x >> y;
      d[i].push_back(make_pair(x - 1, y));
    }
  }
  int ans = 0;
  for(int b = 1; b < (1 << n); b++){
    int res = 0;
    for(int i = 0; i < n; i++){
      if((b & (1 << i)) == 0) continue;         // そもそも不親切と仮定した
      bool flg = true;
      for(auto itr = d[i].begin(); itr != d[i].end(); itr++){
        if(itr->second != ((b & (1 << itr->first)) ? 1 : 0)){
          flg = false;
          break;
        }
      }
      if(flg) res++;
    }
    // if(res == 2) cout << b << endl;
    ans = max(ans, res);
  }
  cout << ans << endl;
}