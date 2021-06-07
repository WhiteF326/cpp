#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int timecal(int c, int d, int t){
  return c + t + floor(d / (double)(t + 1.0));
}

int main(){
  int n, m; cin >> n >> m;
  vector<vector<pair<int, pair<int, int>>>> g(n, vector<pair<int, pair<int, int>>>(0));
  for(int i = 0; i < m; i++){
    int a, b, c, d; cin >> a >> b >> c >> d;
    a--, b--;
    g[a].push_back(make_pair(b, make_pair(c, d)));
  }

  priority_queue<pair<int, int>> q;
  q.push(make_pair(0, 0));
  vector<int> fulldist(n, INT_MAX);
  fulldist[0] = 0;
  bool visitlast = false;
  while(!q.empty()){
    auto dest = q.top();
    q.pop();
    for(int i = 0; i < g[dest.second].size(); i++){
      int nextd = g[dest.second][i].first;
      if(nextd == n - 1) visitlast = true;
      // waittime 未証明……
      int waittime = max(g[dest.second][i].second.second * 2 - g[dest.second][i].second.first, 0);
      int est = timecal(g[dest.second][i].second.first, g[dest.second][i].second.second, dest.first + waittime);
      int ftime = est + dest.first;
      if(fulldist[nextd] > ftime){
        fulldist[nextd] = ftime;
        q.push(make_pair(ftime, i));
      }
    }
  }
  for(int i = 0; i < n; i++){
    cout << fulldist[i] << endl;
  }
  if(visitlast){
    cout << fulldist[n - 1] << endl;
  }else cout << "-1" << endl;
}