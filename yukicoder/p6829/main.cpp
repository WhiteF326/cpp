#include <bits/stdc++.h>
using namespace std;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;

int main(){
  int n, m, l; cin >> n >> m >> l;
  int s, g; cin >> s >> g; s--, g--;
  vector<vector<pair<int, int>>> gp(n, vector<pair<int, int>>(0));
  for(int i = 0; i < m; i++){
    int a, b, t; scanf("%d%d%d", &a, &b, &t);
    a--, b--;
    gp[a].emplace_back(mp(b, t));
    gp[b].emplace_back(mp(a, t));
  }
  int r; cin >> r;
  vector<pair<int, int>> rain(r);
  int p = 0;
  for(int i = 0; i < r; i++){
    int c, d; scanf("%d%d", &c, &d);
    rain[i] = mp(c, d);
  }

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
  q.push(mp(0, s));
  vector<int> dist(n, INT_MAX);
  dist[s] = 0;
  while(!q.empty()){
    auto dest = q.top();
    q.pop();
    for(auto next : gp[dest.second]){
      int arrive = dest.first + next.second;
      int res = -1;
      if(rain[0].first >= arrive) res = 0;
      else{
        for(auto rp : rain){
          if(rp.second < dest.first) continue;
        }
      }
    }
  }
}