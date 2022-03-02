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
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n; cin >> n;
  vector<vector<bool>> stg(n, vector<bool>(n, 0));
  for(int i = 0; i < n; i++){
    string s; cin >> s;
    for(int j = 0; j < n; j++){
      if(s[j] == '#') stg[i][j] = 1;
    }
  }

  // 横
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n - 5; j++){
      // (i, j) を始点とする
      int ctr = 0;
      for(int k = 0; k < 6; k++){
        ctr += stg[i][j + k];
      }
      if(ctr >= 4){
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  // 縦
  for(int i = 0; i < n - 5; i++){
    for(int j = 0; j < n; j++){
      int ctr = 0;
      for(int k = 0; k < 6; k++){
        ctr += stg[i + k][j];
      }
      if(ctr >= 4){
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  // 斜め
  for(int i = 0; i < n - 5; i++){
    for(int j = 0; j < n - 5; j++){
      // 左上から
      int ctr = 0;
      for(int k = 0; k < 6; k++){
        ctr += stg[i + k][j + k];
      }
      if(ctr >= 4){
        cout << "Yes" << endl;
        return 0;
      }

      // 右上から
      ctr = 0;
      for(int k = 0; k < 6; k++){
        ctr += stg[i + 5 - k][j + k];
      }
      if(ctr >= 4){
        cout << "Yes" << endl;
        return 0;
      }
    }
  }

  cout << "No" << endl;
}
