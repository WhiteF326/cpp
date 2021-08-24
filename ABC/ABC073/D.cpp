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

#define infl 1e+9

int main(){
  int n, m, r; cin >> n >> m >> r;
  vector<int> points(r);
  for(int i = 0; i < r; i++){
    int p; cin >> p;
    points[i] = p - 1;
  }
  sort(all(points));

  vector<vector<int>> dist(n, vector<int>(n, infl));
  for(int i = 0; i < m; i++){
    int a, b, c; cin >> a >> b >> c;
    a--, b--;
    dist[a][b] = c;
    dist[b][a] = c;
  }
  for(int i = 0; i < n; i++) dist[i][i] = 0;

  for(int k = 0; k < n; k++){
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        chmin(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  int ans = infl;
  do{
    int res = 0;
    for(int i = 0; i < r - 1; i++){
      res += dist[points[i]][points[i + 1]];
    }
    chmin(ans, res);
  }while(next_permutation(all(points)));
  cout << ans << endl;
}