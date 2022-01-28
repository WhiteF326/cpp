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
#define const constexpr
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;
#define query(t) for(int _ = 0; _ < t; _++)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];

const int minf = -2000000000;


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n, m; cin >> n >> m;
  vector<int> a(n);
  aryin(a, n);
  
  vector<vector<int>> g(n);
  vector<int> inc(n, 0);

  for(int i = 0; i < m; i++){
    int x, y; cin >> x >> y;
    inc[y - 1]++;
    g[x - 1].push_back(y - 1);
  }

  queue<int> q;
  for(int i = 0; i < n; i++) if(inc[i] == 0) q.push(i);

  deque<int> tpl(0);
  while(!q.empty()){
    int dest = q.front();
    q.pop();

    tpl.push_back(dest);
    for(int v : g[dest]){
      inc[v]--;
      if(inc[v] == 0){
        q.push(v);
      }
    }
  }

  vector<int> dp(n, minf);
  for(int i : tpl){
    int cst = (dp[i] == minf ? 0 : dp[i]);
    for(int v : g[i]){
      dp[v] = max(dp[v], a[v] - a[i]);
      dp[v] = max(dp[v], cst + (a[v] - a[i]));
    }
  }

  cout << *max_element(all(dp)) << endl;
}