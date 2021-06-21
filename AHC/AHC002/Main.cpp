#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
using ll = long long;
using ld = long double;

int main(){
  int x, y; cin >> y >> x;
  int fx = x, fy = y;
  // タイル番号
  vector<vector<int>> tiles(50, vector<int>(50));
  // タイルごとの組
  vector<vector<pair<int, int>>> tile_inspect(2500, vector<pair<int, int>>(0));
  int d = 0;
  for(int i = 0; i < 50; i++){
    for(int j = 0; j < 50; j++){
      cin >> d;
      tiles[i][j] = d;
      tile_inspect[d].emplace_back(make_pair(i, j));
    }
  }
  // タイルのスコア
  vector<vector<int>> values(50, vector<int>(50));
  for(int i = 0; i < 50; i++){
    for(int j = 0; j < 50; j++) cin >> values[i][j];
  }
  // 通貨済みかどうか
  vector<vector<bool>> passed(50, vector<bool>(50, false));
  for(auto itr = tile_inspect[tiles[y][x]].begin(); itr != tile_inspect[tiles[y][x]].end(); itr++) passed[itr->first][itr->second] = true;
  
  // 全ての移動パターンを保持
  vector<pair<int, deque<char>>> anslist;
  // 今の移動パターン
  vector<char> res;
  // 選択肢の一覧
  vector<priority_queue<pair<pair<int, int>, char>>> selects(0);
  // 時間保持
  int ti = clock();

  int score = values[y][x];
  // 移動可能かどうかの一覧(速度向上のためここで宣言)
  priority_queue<pair<pair<int, int>, char>> move;
  // 移動ベクトル
  vector<vector<int>> vct = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
  map<char, vector<int, int>> vct_char;
  vct_char['L'] = {-1, 0}, vct_char['U'] = {0, -1}, vct_char['D'] = {0, 1}, vct_char['R'] = {1, 0};
  while(clock() - ti < 17 * CLOCKS_PER_SEC / 10){
    // 最初に継承したresの経路を通る
    for(int i = 0; i < res.size(); i++){
      x += vct_char[res[i]][0], y += vct_char[res[i]][1];
      score += values[y][x];
    }

    while(true){
      bool flg = false;
      // クリーンアップ
      priority_queue<pair<pair<int, int>, char>>().swap(move);
      // 4方向について試す
      for(int i = 0; i < 4; i++){
        // 移動できるときmoveに移動先座標と上下左右いずれかをpush
        int tx = x + vct[i][0], ty = y + vct[i][1];
        if(tx >= 0 && tx < 50 && ty >= 0 && ty < 50){
          if(tiles[ty][tx] != tiles[y][x] && !passed[ty][tx]){
            move.push(make_pair(make_pair(tx, ty), "LUDR"[i]));
            flg = true;
          }
        }
      }
      // 1箇所でも移動できるなら最善手をとる
      if(flg){
        selects.emplace_back(move);
        auto next = move.top();
        x = next.first.first, y = next.first.second;
        auto dest = tile_inspect[tiles[y][x]];
        for(auto itr = dest.begin(); itr != dest.end(); itr++) passed[itr->first][itr->second] = true;
        score += values[y][x];
        res.push_back(next.second);
      }else break;
    }
    // 結果の保存
    anslist.emplace_back(score, res);
    // 経路に選択肢があった場所まで戻る
    while(true){
      res.pop_back();
      if(selects[selects.size() - 1].size() > 1){
        selects[selects.size() - 1].pop();
        res.push_back(selects[selects.size() - 1].top().second);
      }else{
        selects.pop_back();
      }
    }
    if(selects.empty()) break;
    else{
      x = fx, y = fy;
      score = values[y][x];
    }
  }
  while(!res.empty()){
    cout << res.front();
    res.pop_back();
  }cout << endl;
  cerr << score << endl;
}