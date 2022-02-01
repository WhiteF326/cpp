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
#define Give
#define me
#define AcCepted


struct Edge{
  int to;
  int id;
};
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int t; cin >> t;
  query(t){
    int n; cin >> n;
    vector<vector<Edge>> g(n);
    vector<int> ind(n, 0);
    for(int i = 0; i < n - 1; i++){
      int a, b; cin >> a >> b;
      a--, b--;
      g[a].push_back({b, i});
      g[b].push_back({a, i});
      ind[a]++;
      ind[b]++;
    }

    if(*max_element(all(ind)) > 2){
      cout << -1 << endl;
      continue;
    }

    vector<int> ans(n - 1);
    vector<int> before(n, 3);
    bool res = true;
    queue<int> q;
    q.push(0);
    vector<bool> visited(n, false);
    visited[0] = true;

    bool abl = true;

    while(!q.empty()){
      int dest = q.front();
      q.pop();

      int ctr = 0;
      for(auto v : g[dest]){
        if(visited[v.to]) continue;
        q.push(v.to);
        if(before[dest] == 3){
          ans[v.id] = 2 + ctr;
        }else{
          ans[v.id] = 3 - ctr;
        }
        ctr++;
        before[v.to] = ans[v.id];
        visited[v.to] = true;
      }

      if(!abl) break;
    }

    for(int i = 0; i < n - 1; i++){
      cout << ans[i] << " ";
    }
    cout << "\n";
  }
  fflush(stdout);
}