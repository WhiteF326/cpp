#include <bits/stdc++.h>
using namespace std;

#define fs(n) fixed << setprecision(n)
using ll = long long;
using ld = long double;

int main(){
  int n, m; cin >> n >> m;
  vector<vector<bool>> a(n, vector<bool>(n, false)), b(m, vector<bool>(m, false));
  for(int i = 0; i < n; i++){
    string s; cin >> s;
    for(int j = 0; j < n; j++) if(s.substr(j, 1) == "#") a[i][j] = true;
  }
  for(int i = 0; i < m; i++){
    string s; cin >> s;
    for(int j = 0; j < m; j++) if(s.substr(j, 1) == "#") b[i][j] = true;
  }
  for(int i = 0; i < n - m + 1; i++){
    for(int j = 0; j < n - m + 1; j++){
      // from (i, j)
      bool flg = true;
      for(int y = 0; y < m; y++){
        for(int x = 0; x < m; x++){
          if(a[i + y][j + x] != b[y][x]){
            flg = false;
            break;
          }
        }
      }
      if(flg){
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
}