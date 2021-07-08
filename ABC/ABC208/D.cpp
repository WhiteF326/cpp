#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  int n, m; cin >> n >> m;
  vector<vector<pair<ll, int>>> g(n, vector<pair<ll, int>>(0));
  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    a--, b--;
    ll c; cin >> c;
    g[a].push_back(make_pair(c, b));
  }

  for(int s = 0; s < n; s++){
    priority_queue<pair<ll, int>> q;
    q.push(make_pair(0, s));
    vector<ll> fdist(n, LLONG_MAX);
    fdist[s] = 0;
    while(!q.empty()){
      auto dest = q.top();
      q.pop();
      for(int j = 0; j < g[dest.second].size(); j++){
        int ndest = g[dest.second][j].second;
        if(fdist[ndest] > dest.first + g[dest.second][j].first){
          fdist[ndest] = dest.first + g[dest.second][j].first;
          q.push(make_pair(fdist[ndest], ndest));
        }
      }
    }
    
  }

  ll ans = 0;
  for(int k = 0; k < n; k++){
    for(int s = 0; s < n; s++){
      priority_queue<pair<ll, int>> q;
      q.push(make_pair(0, s));
      vector<ll> fdist(n, LLONG_MAX);
      fdist[s] = 0;
      while(!q.empty()){
        auto dest = q.top();
        q.pop();
        for(int j = 0; j < g[dest.second].size(); j++){
          int ndest = g[dest.second][j].second;
          if(fdist[ndest] > dest.first + g[dest.second][j].first){
            fdist[ndest] = dest.first + g[dest.second][j].first;
            if(ndest <= k){
              q.push(make_pair(fdist[ndest], ndest));
            }
          }
        }
      }
      ll res = 0;
      for(int i = 0; i < n; i++){
        // cout << fdist[i] << " ";
        if(fdist[i] != LLONG_MAX){
          res += fdist[i];
        }
      }
      ans += res;
    }
  }
  cout << ans << endl;
}