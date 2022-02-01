#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define all(x) x.begin(), x.end()
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;
#define query(t) for(int _ = 0; _ < t; _++)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];
#define chmin(a, b) a = min(a, b)


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n; cin >> n;
 
  mf_graph<int> graph(n * 2 + 2);
  int end = n * 2 + 1;
 
  vector<pair<int, int>> red(n), blue(n);
  for(int i = 0; i < n; i++){
    int a, b; cin >> a >> b;
    red[i] = {a, b};
    graph.add_edge(0, i + 1, 1);
  }
  for(int i = 0; i < n; i++){
    int a, b; cin >> a >> b;
    blue[i] = {a, b};
    graph.add_edge(i + n + 1, end, 1);
  }
 
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(red[i].first < blue[j].first && red[i].second < blue[j].second){
        graph.add_edge(i + 1, j + n + 1, 1);
      }
    }
  }
 
  cout << graph.flow(0, end) << endl;
}