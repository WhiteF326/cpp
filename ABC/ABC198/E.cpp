#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
using ll = long long;
using ld = long double;

int n;
vector<int> colors(100000);
vector<vector<int>> g(100000, vector<int>(0));
vector<int> used(100000, 0);
vector<bool> visited(100000, false);
priority_queue<int, vector<int>, greater<int>> ans;

void dfs(int p){
  visited[p] = true;
  if(used[colors[p]] == 0){
    ans.push(p);
  }
  used[colors[p]]++;
  for(int i = 0; i < g[p].size(); i++){
    if(visited[g[p][i]] == false) dfs(g[p][i]);
  }
  used[colors[p]]--;
}

int main(){
  cin >> n;
  for(int i = 0; i < n; i++) cin >> colors[i];

  for(int i = 0; i < n - 1; i++){
    int a, b; cin >> a >> b;
    a--, b--;
    g[a].emplace_back(b);
    g[b].emplace_back(a);
  }

  dfs(0);
  while(!ans.empty()){
    cout << ans.top() + 1 << endl;
    ans.pop();
  }
}