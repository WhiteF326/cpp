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

int n;
vector<priority_queue<pdesc(int)>> g(200000, priority_queue<pdesc(int)>());
vector<int> fback(200000, -1);
vector<bool> visited(200000, false);
queue<int> lst;

void dfs(int pt){
  lst.push(pt + 1);
  visited[pt] = true;
  bool flg = true;
  while(!g[pt].empty()){
    int dest = g[pt].top();
    g[pt].pop();
    if(visited[dest]) continue;
    else{
      fback[dest] = pt;
      dfs(dest);
      flg = false;
      break;
    }
  }
  if(flg){
    if(pt != 0) dfs(fback[pt]);
  }
}

int main(){
  cin >> n;
  // 木構造
  for(int i = 0; i < n - 1; i++){
    int a, b; cin >> a >> b;
    a--, b--;
    g[a].push(b);
    g[b].push(a);
  }

  dfs(0);
  while(!lst.empty()){
    cout << lst.front() << " ";
    lst.pop();
  }
}