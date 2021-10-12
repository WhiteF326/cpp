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
  int t; cin >> t;
  query(t){
    int n; cin >> n;
    vector<string> s(3); aryin(s, 3);
    vector<vector<int>> apr(3, vector<int>(2, 0));
    string ans = "";
    for(int t = 0; t <= 1; t++){
      for(int v = 0; v < 2 * n; v++){
        for(int x = 0; x < 3; x++) apr[x][s[x][v] - '0']++;
        for(int b = 0; b < 2; b++){
          bool flg = true;
          for(int p = 0; p < 3; p++) if(!apr[p][b]) flg = false;
          if(flg){
            ans += (char)('0' + b);
            for(int p = 0; p < 3; p++) apr[p][b]--;
          }
        }
        if(ans.size() >= 2 * n + 1) break;
      }
      if(ans.size() >= 2 * n + 1) break;
    }
    cout << ans.substr(0, 2 * n + 1) << endl;
  }
}