#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)
#define please
#define give
#define me
#define more
#define score


// (x1, y1) と (x2, y2) が隣接または同じ座標であるかどうかを判定する
bool isAdjacentOrSame(int x1, int y1, int x2, int y2){
  if(x1 == x2 && y1 == y2){
    return true;
  }
  if(x1 == x2 && abs(y1 - y2) == 1){
    return true;
  }
  if(y1 == y2 && abs(x1 - x2) == 1){
    return true;
  }
  return false;
}
// 上下左右への移動を表す文字列、及び移動量の変数
const string step = "rdlu";
const string upStep = "RDLU";
const vector<vector<int>> way = {
  {0, 1},
  {1, 0},
  {0, -1},
  {-1, 0}
};

// メインプログラム
int main(){
  // 入力を受け取る
  int n; cin >> n;
  vector<int> px(n), py(n), pt(n);
  for(int i = 0; i < n; ++i) cin >> px[i] >> py[i] >> pt[i];
  int m; cin >> m;
  vector<int> hx(m), hy(m);
  for(int i = 0; i < m; ++i) cin >> hx[i] >> hy[i];

  // 次に埋める場所の変数
  vector<int> a(m, 0);

  // 300 ターンのシミュレーションをする
  for(int turn = 0; turn < 300; ++turn){
    // 各人について次の行動を決定する
    for(int i = 0; i < m; ++i){
      // 四方が埋まっているならば何もしない
      if(a[i] == 4){
        cout << ".";
      }else{
        // 次に埋めたい場所を求める
        int dx = hx[i] + way[a[i]][0];
        int dy = hy[i] + way[a[i]][1];

        // 埋められなかったら True になる
        bool flg = false;

        // 埋めたい場所に人がいるならその方向は飛ばす
        for(int j = 0; j < m; ++j){
          if(hx[j] == dx && hy[j] == dy){
            cout << ".";
            ++a[i];
            flg = true;
            break;
          }
        }
        // 埋めたい場所にペットが居たら一旦諦める
        if(!flg){
          for(int j = 0; j < n; ++j){
            if(isAdjacentOrSame(px[j], py[j], dx, dy) || (px[j] == dx && py[j] == dy)){
              cout << ".";
              flg = true;
              break;
            }
          }
        }
        // 埋められるので埋める
        if(!flg){
          cout << step[a[i]];
          ++a[i];
        }
      }
    }
    cout << endl;

    // 各ペットの位置を更新する
    vector<string> pt(n);
    aryin(pt, n);
    for(int i = 0; i < n; ++i){
      for(char c : pt[i]){
        for(int j = 0; j < 4; ++j){
          if(c == upStep[j]){
            px[i] += way[j][0];
            py[i] += way[j][1];
            break;
          }
        }
      }
    }
  }

  please give me more score return 0;
}
