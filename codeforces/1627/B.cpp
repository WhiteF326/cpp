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
    int n, m; cin >> n >> m;
    vector<int> depth(n * m, 0);
    vector<bool> visited(n * m, false);
    int fst = n / 2 + m / 2;

    queue<int> q;
    q.push(n / 2 * m + m / 2);
    visited[n / 2 * m + m / 2] = true;
    if(n % 2 == 0){
      q.push((n / 2 - 1) * m + m / 2);
      visited[(n / 2 - 1) * m + m / 2] = true;
    }
    if(m % 2 == 0){
      q.push(n / 2 * m + m / 2 - 1);
      visited[n / 2 * m + m / 2 - 1] = true;
    }
    if(m % 2 == 0 && n % 2 == 0){
      q.push((n / 2 - 1) * m + m / 2 - 1);
      visited[(n / 2 - 1) * m + m / 2 - 1] = true;
    }
    vector<vector<int>> act = {
      {-1, 0},
      {0, -1},
      {0, 1},
      {1, 0}
    };

    while(!q.empty()){
      int dest = q.front();
      q.pop();
      
      int cx = dest % m, cy = dest / m;

      for(auto v : act){
        int dx = cx + v[0], dy = cy + v[1];
        if(dx < 0 || dx >= m || dy < 0 || dy >= n) continue;
        if(visited[dy * m + dx]) continue;

        q.push(dy * m + dx);
        depth[dy * m + dx] = depth[dest] + 1;
        visited[dy * m + dx] = true;
      }
    }
    sort(all(depth));
    for(int v : depth) cout << v + fst << " ";
    cout << "\n";
  }
  fflush(stdout);
}