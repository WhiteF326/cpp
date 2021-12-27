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
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;
#define query(t) for(int _ = 0; _ < t; _++)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


#define limit 500000
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n; cin >> n;
  vector<int> position(n, 0);
  vector<int> p(n);
  aryin(p, n);

  int m; cin >> m;
  dsu d(n);
  vector<vector<pair<int, int>>> g(n);
  vector<pair<int, int>> swp(m);
  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    g[a - 1].push_back({b - 1, i});
    g[b - 1].push_back({a - 1, i});
    d.merge(a - 1, b - 1);
    swp[i] = {a - 1, b - 1};
  }

  for(int i = 0; i < n; i++){
    if(p[i] - 1 != i){
      if(!d.same(p[i] - 1, i)){
        cout << -1 << endl;
        return 0;
      }
    }
    position[p[i] - 1] = i;
  }

  vector<bool> sorted(n, false);
  deque<int> act;
  // 大きい数字から順に移動する
  for(int i = 0; i < n; i--){
    if(sorted[i]) continue;
    queue<int> q;
    q.push(p[i]);
    vector<int> visited(0);
    
  }

  cout << act.size() << endl;
  while(!act.empty()){
    cout << act.front() + 1 << " ";
    act.pop_front();
  }

  cout << endl;
}