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
  int h, w; cin >> h >> w;

  mf_graph<ll> g(h * w);
  vector<vector<int>> hlist(w), wlist(h);
  int start, goal;
  for(int i = 0; i < h; i++){
    string s; cin >> s;
    for(int j = 0; j < w; j++){
      if(s[j] != '.'){
        hlist[j].push_back(i);
        wlist[i].push_back(j);
      }
      if(s[j] == 'S'){
        start = i * w + j;
      }
      if(s[j] == 'T'){
        goal = i * w + j;
      }
    }
  }

  for(int i = 0; i < w; i++){
    int n = hlist[i].size();
    for(int j = 0; j < n; j++){
      for(int k = 0; k < n; k++){
        g.add_edge(i + hlist[i][j] * w, i + hlist[i][k] * w, 1);
      }
    }
  }
  for(int i = 0; i < h; i++){
    int n = wlist[i].size();
    for(int j = 0; j < n; j++){
      for(int k = 0; k < n; k++){
        g.add_edge(i * w + wlist[i][j], i * w + wlist[i][k], 1);
      }
    }
  }

  cout << g.flow(start, goal) << endl;
}