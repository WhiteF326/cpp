#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;
#define query(t) for(int _ = 0; _ < t; _++)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


int n;
vector<int> v(300000, 0), w(300000, 0);
vector<vector<int>> queries(300000);
vector<map<int, int>> anslist(300000);
vector<vector<int>> dp(20, vector<int>(100010, 0));

int depth = 0;

void dfs(int p){
  if(p >= n) return;
  // depth -> depth + 1
  for(int i = 0; i <= 100000; i++){
    if(i >= w[p]) dp[depth + 1][i] = max(dp[depth][i - w[p]] + v[p], dp[depth][i]);
    else dp[depth + 1][i] = dp[depth][i];
  }
  for(int query : queries[p]){
    anslist[p][query] = dp[depth + 1][query];
  }
  depth++;
  dfs(p * 2 + 1);
  dfs(p * 2 + 2);
  depth--;
}

int main(){
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> v[i] >> w[i];
  }
  int q; cin >> q;
  vector<pair<int, int>> querylist(q);
  for(int i = 0; i < q; i++){
    int v, l; cin >> v >> l;
    queries[v - 1].push_back(l);
    querylist[i] = {v - 1, l};
  }

  dfs(0);

  for(int i = 0; i < q; i++){
    int v = querylist[i].first, l = querylist[i].second;
    cout << anslist[v][l] << endl;
  }
}