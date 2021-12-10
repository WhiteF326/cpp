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
  int n, g, e; cin >> n >> g >> e;
  n++;
  mf_graph<int> graph(n);
  for(int i = 0; i < g; i++){
    int p; cin >> p;
    graph.add_edge(p, n - 1, 1);
  }
  for(int i = 0; i < e; i++){
    int a, b; cin >> a >> b;
    graph.add_edge(a, b, 1);
    graph.add_edge(b, a, 1);
  }

  cout << graph.flow(0, n - 1) << endl;
}