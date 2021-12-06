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
#define chmin(a, b) a = min(a, b)

#define pli pair<ll, int>

int main(){
  int n, m; cin >> n >> m;
  vector<vector<vector<int>>> g(n, vector<vector<int>>(0, vector<int>(3, 0)));
  for(int i = 0; i < m; i++){
    int a, b, c, d; cin >> a >> b >> c >> d;
    a--, b--;
    g[a].push_back({b, c, d});
    g[b].push_back({a, c, d});
  }

  priority_queue<pli, vector<pli>, greater<pli>> pq;
  pq.push({0, 0});
  vector<ll> dist(n, LLONG_MAX);
  dist[0] = 0;

  while(!pq.empty()){
    auto dest = pq.top();
    pq.pop();

    for(auto p : g[dest.second]){
      // sqrt(d) 付近が最適
      ll wait = (ll)floor(sqrt(p[2]));
      ll arrive = LLONG_MAX;
      if(dest.first <= wait){
        arrive = dest.first + p[1] + floor(p[2] / (dest.first + 1));
      }else{
        for(ll i = max(0LL, wait - 2); i <= wait + 4LL; i++){
          // i を wait time として計算してみる
          ll test = floor(p[2] / (i + 1)) + i + p[1];
          arrive = min(arrive, test);
        }
      }
      
      
      if(dist[p[0]] > arrive){
        dist[p[0]] = arrive;
        pq.push({arrive, p[0]});
      }
    }
  }

  if(dist[n - 1] == LLONG_MAX){
    cout << -1 << endl;
  }else{
    cout << dist[n - 1] << endl;
  }
}