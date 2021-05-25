#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j);
using ll = long long;
using ld = long double;

int main(){
  int n, m; cin >> n >> m;
  vector<vector<bool>> relates(n, vector<bool>(n, false));
  for(int i = 0; i < m; i++){
    int x, y; cin >> x >> y;
    x--, y--;
    relates[x][y] = true;
    relates[y][x] = true;
  }
  int ans = 0;
  for(int i = 1; i < (1 << n); i++){
    vector<int> teamList(0);
    for(int j = 0; j < n; j++){
      if(i & (1 << j)) teamList.push_back(j);
    }
    bool flg = true;
    for(int j = 0; j < teamList.size() - 1; j++){
      for(int k = j + 1; k < teamList.size(); k++){
        if(!relates[teamList[j]][teamList[k]]) flg = false;
      }
    }
    if(flg){
      ans = max(ans, (int)teamList.size());
    }
  }
  cout << ans << endl;
}