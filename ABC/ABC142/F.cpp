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


bool dfs(int p){
  // 愚直に加算する
}

int main(){
  int n, m; cin >> n >> m;

  vector<vector<int>> g(n);
  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    g[a - 1].push_back(b - 1);
  }

  for(int i = 0; i < n; i++){
    // auto st = bfs(i);
    // if(st) return 0;
  }
  cout << -1 << endl;
}