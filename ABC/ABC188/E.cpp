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
#define graph(g, n) vector<vector<int>> g(n)

const int minfl = -2000000000;


int main(){
  int n, m;
  cin >> n >> m;
  vector<int> a(n); aryin(a, n);
  
  graph(g, n);
  vector<int> inlevel(n, 0);

  for(int i = 0; i < m; i++){
    int x, y; cin >> x >> y;
    inlevel[y - 1]++;
    g[x - 1].push_back(y - 1);
  }

  queue<int> q;
  for(int i = 0; i < n; i++) if(inlevel[i] == 0) q.push(i);

  vector<int> tpl(0);
  while(!q.empty()){
    int dest = q.front();
    q.pop();

    tpl.push_back(dest);
    for(int v : g[dest]){
      inlevel[v]--;
      if(inlevel[v] == 0){
        q.push(v);
      }
    }
  }

  vector<int> dp(n, minfl);
  for(int i : tpl){
    int cst = (dp[i] == minfl ? 0 : dp[i]);
    for(int v : g[i]){
      dp[v] = max(dp[v], a[v] - a[i]);
      dp[v] = max(dp[v], cst + (a[v] - a[i]));
    }
  }

  // for(int p : dp) cout << p << " ";
  // cout << endl;

  cout << *max_element(all(dp)) << endl;
}