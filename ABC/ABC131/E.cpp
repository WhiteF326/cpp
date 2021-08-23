#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define const constexpr
#define pdesc(t) t, vector<t>, greater<t>
#define chmin(a, b) a = min(a, b)
using ll = long long;
using ld = long double;

int main(){
  int n; cin >> n;
  vector<vector<int>> g(n, vector<int>(0));
  for(int i = 0; i < n - 1; i++){
    int a, b; cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  // 各頂点からの距離 bfs
  vector<int> fdist(n, 0), sdist(n, 0);
  queue<int> q;
  vector<bool> visited(n, false);

  // fdist
  q.push(0);
  // for(int i = 0; i < n; i++) visited[i] = false;
  auto bfs = [&](vector<int>& depth){
    while(!q.empty()){
      int dest = q.front();
      q.pop();

      for(int pos : g[dest]){
        if(!visited[pos]){
          visited[pos] = true;
          depth[pos] = depth[dest] + 1;
          q.push(pos);
        }
      }
    }
  };
  bfs(fdist);

  // sdist
  q.push(n - 1);
  for(int i = 0; i < n; i++) visited[i] = false;
  bfs(sdist);

  // compare
  int fpt = 0, spt = 0;
  for(int i = 0; i < n; i++){
    if(fdist[i] <= sdist[i]) fpt++;
    else if(fdist[i] > sdist[i]) spt++;
  }

  if(fpt > spt) cout << "Fennec" << endl;
  else cout << "Snuke" << endl;
}