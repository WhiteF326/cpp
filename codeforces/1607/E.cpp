#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int t; cin >> t;
  query(t){
    int n, m; cin >> n >> m;
    int mx = 0, my = 0, nx = 0, ny = 0;
    int cx = 0, cy = 0;
    string s; cin >> s;
    bool flg = false;
    for(char c : s){
      if(c == 'L'){
        cx--;
      }
      if(c == 'R'){
        cx++;
      }
      if(c == 'U'){
        cy--;
      }
      if(c == 'D'){
        cy++;
      }

      if(max(mx, cx) - min(nx, cx) >= m || max(my, cy) - min(ny, cy) >= n){
        // 1 手戻る
        if(c == 'L') cx++;
        if(c == 'R') cx--;
        if(c == 'U') cy++;
        if(c == 'D') cy--;
        
        cout << -ny + 1 << " " << -nx + 1 << endl;
        flg = true;
        break;
      }else{
        nx = min(nx, cx);
        mx = max(mx, cx);
        ny = min(ny, cy);
        my = max(my, cy);
      }
    }
    if(!flg){
      cout << -ny + 1 << " " << -nx + 1 << endl;
    }
  }
}