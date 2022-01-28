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
  
  vector<vector<int>> trd(n * 2, vector<int>(n * 2, 0));
  for(int i = 0; i < n * 2 - 1; i++){
    for(int j = i + 1; j < n * 2; j++){
      int a; cin >> a;
      trd[i][j] = a;
      trd[j][i] = a;
    }
  }
  
  vector<int> dp(1 << (n * 2), 0);
  for(int i = 0; i < 1 << (n * 2); i++){
    for(int dest = 0; dest < 2 * n; dest++){
      if(i & (1 << dest)) continue;

      for(int j = 0; j < 2 * n; j++){
        if(dest == j) continue;
        if(i & (1 << j)) continue;

        chmax(dp[i | (1 << j) | (1 << dest)], dp[i] ^ trd[dest][j]);
      }
    }
  }

  cout << dp[(1 << (n * 2)) - 1] << endl;
}