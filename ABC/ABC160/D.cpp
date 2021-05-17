#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, x, y; cin >> n >> x >> y;
  x--, y--;

  vector<vector<int>> gr(n, vector<int>(0));
  for(int i = 0; i < n - 1; i++){
    gr[i].push_back(i + 1);
    gr[i + 1].push_back(i);
  }
  gr[x].push_back(y);
  gr[y].push_back(x);

  map<pair<int, int>, int> res;

  for(int i = 0; i < n - 1; i++){
    queue<int> q;
    q.push(i);
    vector<bool> visited(n, false);
    for(int j = 0; j < i; j++){
      visited[j] = true;
    }
    vector<int> dist(n, 0);
    while(!q.empty()){
      int dest = q.front();
      q.pop();
      visited[i] = true;
      for(int j = 0; j < gr[dest].size(); j++){
        if(visited[gr[dest][j]] == false){
          dist[gr[dest][j]] = dist[dest] + 1;
          visited[gr[dest][j]] = true;
          q.push(gr[dest][j]);
        }
      }
    }
    for(int j = 0; j < n; j++){
      int l = min(i, j);
      int r = max(i, j);
      if(dist[j] && res[make_pair(l, r)]){
        
        res[make_pair(l, r)] = min(dist[j], res[make_pair(l, r)]);
      }
    }
  }

  vector<int> ans(n, 0);
  for(auto itr = res.begin(); itr != res.end(); itr++){
    ans[itr->second]++;
  }
  for(int i = 1; i <= n - 1; i++){
    cout << ans[i] << endl;
  }

}