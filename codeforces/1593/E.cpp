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


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int t; cin >> t;
  query(t){
    int n, k; cin >> n >> k;

    vector<vector<int>> g(n);
    vector<int> cnct(n, 0);
    for(int i = 0; i < n - 1; i++){
      int a, b; cin >> a >> b;
      g[a - 1].push_back(b - 1);
      g[b - 1].push_back(a - 1);
      cnct[a - 1]++;
      cnct[b - 1]++;
    }

    vector<int> leafs(0);
    for(int i = 0; i < n; i++){
      if(cnct[i] <= 1) leafs.emplace_back(i);
    }

    queue<int> q;
    for(int v : leafs) q.push(v);
    vector<bool> visited(n, false);
    vector<int> tps(0);
    vector<bool> used(n, false);

    while(!q.empty()){
      int dest = q.front();
      q.pop();
      tps.emplace_back(dest);
      visited[dest] = true;

      for(int v : g[dest]){
        if(visited[v]) continue;
        cnct[v]--;
        if(cnct[v] <= 1){
          q.push(v);
        }
      }

      cout << dest << " : ";
      for(int i = 0; i < n; i++){
        cout << cnct[i] <<" ";
      }cout << endl;
    }

    vector<int> ptr(n, 0);
    for(int i = 0; i < n; i++) ptr[tps[i]] = i;

    vector<int> depth(n, 0);

    for(int i = 0; i < n; i++){
      for(int v : g[tps[i]]){
        if(ptr[v] < ptr[tps[i]]) continue;
        depth[v] = max(depth[v], depth[tps[i]] + 1);
      }
    }
    
    for(int i = 0; i < n; i++){
      cout << depth[i] <<" ";
    }cout << endl;

    int ans = n;
    for(int i = 0; i < n; i++){
      if(depth[i] < k) ans--;
    }
    cout << ans << endl;
  }
}