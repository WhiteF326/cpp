#include <bits/stdc++.h>
using namespace std;

#define infl 1e+9

int main(){
  int n, m; cin >> n >> m;
  vector<vector<pair<int, int>>> g(n);
  
  int a, b; cin >> a >> b;
  a--, b--;
  for(int i = 0; i < m; i++){
    int x, y, c; cin >> x >> y >> c;
    x--, y--;
    g[x].push_back(make_pair(y, c));
    g[y].push_back(make_pair(x, c));
  }
  
  
}
