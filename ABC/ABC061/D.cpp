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


struct Edge{
  int from;
  int to;
  ll weight;
};
bool bellmanFord(int v, const vector<Edge>& es, vector<ll>& cost, int s = 0, int g = -1){
  if(g == -1){
    g = v - 1;
  }

  constexpr ll INF = 1LL << 61;

  cost.assign(v, INF);
  cost[s] = 0;

  for(int i = 0; i < v * 2; i++){
    for(auto& e : es){
      if(cost[e.from] < INF && cost[e.from] + e.weight < cost[e.to]){
        if(i >= v - 1 && e.to == g){
          return false;
        }else if(i >= v - 1){
          cost[e.to] = -INF;
        }else{
          cost[e.to] = cost[e.from] + e.weight;
        }
      }
    }
  }

  return true;
}
int main(){
  int n, m; cin >> n >> m;

  vector<Edge> e(m);
  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    ll c; cin >> c;
    e[i] = {a - 1, b - 1, -c};
  }

  vector<ll> cost(n);

  if(bellmanFord(n, e, cost)){
    cout << -cost[n - 1] << endl;
  }else{
    cout << "inf" << endl;
  }
}