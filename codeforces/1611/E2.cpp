#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define const constexpr
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int t; cin >> t;
  query(t){
    int n, k; cin >> n >> k;
    vector<int> x(k);
    aryin(x, k);
    vector<vector<int>> g(n);
    vector<int> ind(n, 0);
    for(int i = 0; i < n - 1; i++){
      int a, b; cin >> a >> b;
      g[a - 1].push_back(b - 1);
      g[b - 1].push_back(a - 1);
      ind[a - 1]++;
      ind[b - 1]++;
    }

    vector<int> depth(n, 0);
    vector<int> visited(n, false);
    queue<int> q;
    for(int v : x){
      q.push(v - 1);
      visited[v - 1] = true;
    }

    while(!q.empty()){
      int dest = q.front();
      q.pop();

      for(int v : g[dest]){
        if(visited[v]) continue;
        visited[v] = true;
        q.push(v);
        depth[v] = depth[dest] + 1;
      }
    }

    int ans = 0;

    q.push(0);
    fill(all(visited), false);
    vector<bool> access(n, false);
    vector<int> ndepth(n, 0);
    while(!q.empty()){
      int dest = q.front();
      access[dest] = true;
      q.pop();

      for(int v : g[dest]){
        if(visited[v]) continue;
        if(depth[v] <= ndepth[dest] + 1){
          visited[v] = true;
          ans++;
        }else{
          q.push(v);
          visited[v] = true;
          ndepth[v] = ndepth[dest] + 1;
        }
      }
    }

    bool flg = true;
    for(int i = 1; i < n; i++){
      if(ind[i] <= 1 && access[i]){
        cout << -1 << endl;
        flg = false;
        break;
      }
    }
    if(flg){
      cout << ans << endl;
    }
  }
}