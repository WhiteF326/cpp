#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define const constexpr
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


vector<vector<int>> way = {
  {-1, 0},
  {0, -1},
  {0, 1},
  {1, 0}
};
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int t; cin >> t;
  query(t){
    int n; cin >> n;
    vector<vector<ll>> v(n * 2, vector<ll>(n * 2, 0));

    for(int i = 0; i < n * 2; i++){
      for(int j = 0; j < n * 2; j++){
        cin >> v[i][j];
      }
    }
    
    // 区間幅 n
    vector<vector<ll>> sv(n * 2, vector<ll>(n * 2, 0));
    for(int i = 0; i < n * 2; i++){
      for(int j = 0; j < n * 2; j++){
        sv[i][j] += v[i][j];
        if(i < n) sv[i + n][j] -= v[i][j];
        if(j < n) sv[i][j + n] -= v[i][j];
        if(i < n && j < n) sv[i + n][j + n] += v[i][j];
      }
    }
    for(int i = 0; i < n * 2; i++){
      for(int j = 0; j < n * 2 - 1; j++){
        sv[i][j + 1] += sv[i][j];
      }
    }
    for(int i = 0; i < n * 2 - 1; i++){
      for(int j = 0; j < n * 2; j++){
        sv[i + 1][j] += sv[i][j];
      }
    }
    
    priority_queue<pair<ll, int>> q;
    q.push({0LL, (n - 1) * 2 * n + (n - 1)});
    vector<ll> depth((2 * n) * (2 * n), LLONG_MAX);
    depth[(n - 1) * (n - 1)] = 0;

    while(!q.empty()){
      auto dest = q.top();
      q.pop();

      ll cc = dest.first;
      int cy = dest.second / (2 * n), cx = dest.second % (2 * n);

      for(int v = 0; v < 4; v++){
        int dy = cy + way[v][0], dx = cx + way[v][1];
        if(dy < n - 1 || dy >= n * 2 || dx < n - 1 || dx >= n * 2) continue;

        if(cc + sv[dy][dx] < depth[dy * 2 * n + dx]){
          depth[dy * 2 * n + dx] = cc + sv[dy][dx];
          q.push({cc + sv[dy][dx], dy * 2 * n + dx});
        }
      }
    }

    cout << depth[n * n * 4 - 1] << endl;
  }
}