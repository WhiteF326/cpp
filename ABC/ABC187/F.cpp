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
  int n, m; cin >> n >> m;
  vector<vector<int>> g(n, vector<int>(n, 0));
  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    g[a - 1][b - 1] = 1;
    g[b - 1][a - 1] = 1;
  }

  // 集合[i] に含まれる辺の個数
  vector<int> v(1 << n, 0);
  for(int i = 0; i < n; i++){
    v[1 << i] = 1;
  }
  for(int i = 1; i < (1 << n); i++){
    for(int j = 0; j < n; j++){
      if(i & (1 << j)) continue;
      int res = 0;
      
      v[i | (1 << j)] = v[i];
    }
  }
}