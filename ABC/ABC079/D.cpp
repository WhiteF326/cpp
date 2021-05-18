#include <bits/stdc++.h>
using namespace std;

int main(){
  int h, w; cin >> h >> w;
  vector<vector<int>> dists(10, vector<int>(10, 0));
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++){
      cin >> dists[i][j];
    }
  }
  // dj
  // 距離, 頂点
  vector<int> distfrom1(10, 0);
  for(int i = 0; i < 10; i++){
    if(i == 1) continue;
    priority_queue<pair<int, int>> q;
    q.push(make_pair(0, i));
    vector<int> fulldist(10, INT_MAX);
    fulldist[i] = 0;
    while(!q.empty()){
      auto dest = q.top();
      q.pop();
      for(int j = 0; j < 10; j++){
        // 今見ている場所
        if(fulldist[j] > dest.first + dists[dest.second][j]){
          fulldist[j] = dest.first + dists[dest.second][j];
          q.push(make_pair(dists[dest.second][j] + dest.first, j));
        }
      }
    }
    distfrom1[i] = fulldist[1];
  }

  map<int, int> stage;
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      int x; cin >> x;
      if(x >= 0) stage[x]++;
    }
  }

  int ans = 0;
  for(int i = 0; i < 10; i++){
    ans += stage[i] * distfrom1[i];
  }
  cout << ans << endl;

}