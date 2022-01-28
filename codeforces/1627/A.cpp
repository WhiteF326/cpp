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
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i]


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int t; cin >> t;
  query(t){
    int n, m, r, c; cin >> n >> m >> r >> c;
    vector<string> s(n);
    int b = 0;
    for(int i = 0; i < n; i++){
      string t; cin >> t;
      s[i] = t;
      b += count(all(t), 'B');
    }
    if(!b){
      cout << -1 << "\n";
    }else{
      r--, c--;
      if(s[r][c] == 'B'){
        cout << 0 << "\n";
        continue;
      }
      bool flg = false;
      for(int i = 0; i < m; i++){
        if(s[r][i] == 'B') flg = true;
      }
      for(int i = 0; i < n; i++){
        if(s[i][c] == 'B') flg = true;
      }

      cout << 2 - flg << "\n";
    }
  }
  fflush(stdout);
}