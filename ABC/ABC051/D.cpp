#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;
constexpr int infl = 1000000000;
#define iwi pair<int, int>

template <typename T>
bool chmin(T &a, const T& b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

iwi ascpair(iwi x){
  if(x.first > x.second) return {x.second, x.first};
  else return x;
}

int main(){
  int n, m; cin >> n >> m;
  
  vector<vector<iwi>> g(n);
  for(int i = 0; i < m; i++){
    int a, b, c; cin >> a >> b >> c;
    a--, b--;
    g[a].push_back({b, c});
    g[b].push_back({a, c});
  }

  set<iwi> ans;

  for(int i = 0; i < n; i++){
    priority_queue<iwi, vector<iwi>, greater<iwi>> q;
    q.push({0, i});
    vector<iwi> depth(n, {infl, -1});
    depth[i] = {0, -1};

    while(!q.empty()){
      auto dest = q.top();
      q.pop();
      
      for(auto v : g[dest.second]){
        int arrive = dest.first + v.second;
        if(chmin(depth[v.first].first, arrive)){
          depth[v.first].second = dest.second;
          // ans.insert(ascpair({dest.second, v.first}));
          q.push({arrive, v.first});
        }
      }
    }

    for(int j = 0; j < n; j++){
      if(i == j) continue;
      int prev = depth[j].second;
      ans.insert(ascpair({j, prev}));
    }
  }

  cout << m - ans.size() << endl;
}