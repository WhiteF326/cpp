#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n, m;
vector<bool> ability(100000, false);
vector<pair<int, int>> oplist(100000, make_pair(0, 0));
vector<pair<int, int>> ballList(100000, make_pair(0, 1));
int redptr = 0;

int dfs(int step){
  // cout << step << endl;
  if(step == m){
    // for(int i = 0; i < n; i++){
    //   cout << ballList[i].first << " " << ballList[i].second << endl;
    // }
    ability[redptr] = true;
    return 0;
  }
  int l = oplist[step].first, r = oplist[step].second;
  // 赤ボールがある場合
  if(ballList[l].first > 0){
    ballList[l].first--;
    ballList[r].first++;
    redptr = r;
    dfs(step + 1);
    ballList[l].first++;
    ballList[r].first--;
    redptr = l;
  }
  // 白ボールがある場合
  if(ballList[l].second > 0){
    ballList[l].second--;
    ballList[r].second++;
    dfs(step + 1);
    ballList[l].second++;
    ballList[r].second--;
  }
  return 0;
}

int main(){
  // 選択のdfs

  cin >> n >> m;
  for(int i = 0; i < m; i++){
    int x, y; cin >> x >> y; x--; y--;
    oplist[i].first = x, oplist[i].second = y;
  }
  // 赤,白
  ballList[0].first = 1, ballList[0].second = 0;

  dfs(0);

  int ans = 0;
  for(int i = 0; i < n; i++){
    ans += ability[i];
  }
  cout << ans << endl;

}