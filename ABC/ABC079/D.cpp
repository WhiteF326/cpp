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
  priority_queue<pair<int, int>> q;
  q.push(make_pair(0, 1));
  vector<int> fulldist(10, INT_MAX);
  fulldist[1] = 0;
  while(!q.empty()){
    auto dest = q.top();
    q.pop();
    for(int i = 0; i < 10; i++){
      // 今見ている場所
      // if(i == dest.second) continue;
      if(fulldist[dest.second] > dest.first){
        fulldist[dest.second] = dest.first;
        q.push(make_pair(dists[dest.second][i] + fulldist[dest.second], i));
      }
    }
  }

  for(int i = 0; i < 10; i++){
    cout << fulldist[i] << " ";
  }cout << endl;

  map<int, int> stage;
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      int x; cin >> x;
      if(x >= 0) stage[x]++;
    }
  }

  int ans = 0;
  for(int i = 0; i < 10; i++){
    ans += stage[i] * fulldist[i];
  }
  cout << ans << endl;

}