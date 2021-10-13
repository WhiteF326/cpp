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
#define query(t) for(int _ = 0; _ < t; _++)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


int main(){
  int n, m; cin >> n >> m;
  
  vector<int> points(n, INT_MAX);
  dsu d(n);
  vector<vector<pair<int, int>>> g(n);
  query(m){
    int l, r, dis; cin >> l >> r >> dis;
    l--, r--;
    g[l].push_back(mp(r, dis));
    g[r].push_back(mp(l, -dis));

    d.merge(l, r);
  }

  // 連結成分ごとにある頂点を 0 として計算
  auto gr = d.groups();
  vector<int> visited(n, false);
  for(auto p : gr){
    points[p[0]] = 0;
    int minpt = 0, maxpt = 0;
    queue<int> q;
    q.push(p[0]);
    while(!q.empty()){
      int dest = q.front();
      q.pop();

      for(auto v : g[dest]){
        if(visited[v.first]){
          // 距離が一致していなければ "No"
          if(points[v.first] != points[dest] + v.second){
            cout << "No" << endl;
            return 0;
          }
        }else{
          // 距離が未設定なので設定する
          points[v.first] = points[dest] + v.second;
          visited[v.first] = true;
          minpt = min(minpt, points[v.first]);
          maxpt = max(maxpt, points[v.first]);
          q.push(v.first);
        }
      }
    }
    // 幅が大きすぎる
    if(maxpt - minpt > 1000000000){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}