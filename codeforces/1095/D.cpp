#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


int n;
vector<vector<int>> g(200000);
vector<bool> visited(200000, false);
vector<int> a(200000), b(200000);

void dfs(int p){
  visited[p] = true;
  cout << p + 1 << " ";
  for(int v : g[p]){
    if(visited[v]) continue;
    if(a[p] == v || b[p] == v) dfs(v);
  }
}

int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  cin >> n;
  for(int i = 0; i < n; i++){
    int x, y; cin >> x >> y;
    g[x - 1].push_back(y - 1);
    g[y - 1].push_back(x - 1);
    a[i] = x - 1;
    b[i] = y - 1;
  }

  dfs(0);
}