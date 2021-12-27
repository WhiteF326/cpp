#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#endif
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


vector<vector<pair<int, char>>> g(30);
map<int, bitset<30>> m;
vector<bool> visited(30, false);
#define start 3
#define goal 6
int current = 0;
string path = "";
void dfs(int p, ll dim){
  cout << p << " " << dim << endl;
  m[dim].set(p, true);
  if(p == goal && dim == 0){
    cout << path << endl;
    return;
  }else if(p == goal){
    return;
  }
  for(auto v : g[p]){
    path += v.second;
    if(v.first >= 10 && v.first < 20){
      if(m[dim * 2].test(v.first - 10)) continue;
      dfs(v.first - 10, dim * 2);
    }else if(v.first >= 20){
      if(m[dim * 2].test(v.first - 20)) continue;
      dfs(v.first - 20, dim * 2 + 1);
    }else{
      dfs(v.first, dim);
    }
    path.pop_back();
  }
  m[dim].set(p, false);
}

int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  ifstream ifs("in.txt");
  for(int i = 0; i < 25; i++){
    int a, b; ifs >> a >> b;
    char c; ifs >> c;
    g[a - 1].push_back({b - 1, c});
  }

  for(auto& x : g) sort(all(x));

  dfs(start, 0);
}