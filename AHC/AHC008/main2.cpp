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
// 回転先の方向文字列
map<char, string> rotatedAct = {
  {'R', "RULD"},
  {'U', "ULDR"},
  {'L', "LDRU"},
  {'D', "DRUL"},
  {'r', "ruld"},
  {'u', "uldr"},
  {'l', "ldru"},
  {'d', "drul"},
  {'.', "...."}
};
// 与えられた座標を (15, 15) を中心にして時計回りに 90 度回転する
void rotate90(int &x, int &y){
  // 15, 15 を中心に変換する
  x -= 15;
  y -= 15;
  // x, y -> y, -x
  int tmp = x;
  x = y;
  y = -tmp;
  // 元に戻す
  x += 15;
  y += 16;
}
// 終端の座標
vector<int> xEnd = {
  11, 0, 13, 29
};
vector<int> yEnd = {
  29, 16, 0, 13
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

  /*
    ※ もしかしたら、ペット用のスペースの高さを上げればスコアが増えるかもしれない

    border = 18 として、
    縦 (30 - border - 1) マス横 30 マスの矩形を下方向にペット用のスペースとして用意。
    それ以外を頑張って人間用の領域とする。
    作る辺は下だけでよい。

    ただ、ペットがいる場所の分散具合によっては、
    下方向に人間用の領域を取る方が良い場合や、
    あるいは左右に人間用の領域を取る方が良い場合があるかもしれない。

    が、実装をバグらせたので、回転させずに提出してみる。(スコアの差がヤバいが……)
    (
      2/13 3:39 上で提出、20M pt。
      それほど大きな改善にならずちょっとがっかり。やっぱり方向回転は必須。
      あと、ペットごとに移動量の差があることを考慮すると、その分の重みも必要そう。

      さらに、人間がいる場所の分散具合によっては、
      border を 18 以外の値にしてみるのも良いかもしれない。
      人間が到達できる領域が狭くなることの方がダメージ量としては小さそうだけど、
      方向の回転が出来てなおスコアが微妙だったらやってみる。
    )

    (
      2/13 20:52 回転を実装した。28M pt。
      これもそれほど大きな改善にならず。というか seed=0 の点数が落ちてる。
      でも、下振れの幅は割と小さくなった。
    )

    多少ペット用のスペースにペットが入り込んでも許す。
    頑張って形を取れば締め出せそうでもあるけど、それは難しいので一旦やめる。
    というか、移動の特性上、上の方でタイプ 1, 2, 3, 5 のペットが出現したら下の方に狙って動かすこと自体ほぼ無理。

    下辺だけなら埋める場所も少ないので、下から 1 人を選んで下辺を作らせる。
    特に終盤はどうしても締め出しづらくなるが、どうにかする。
    
    選ばれなかった m-1 人は、いったん下まで移動させる。

    (以下とりやめ もしかしたらやるかも)
    // そして、299 ターンぎりぎりで人間側の領域に入れる。
    // 最後に下の辺を完全に締め切る為の 1 ターンが必要であることに注意。

    (こっちが主方針)
    そして、順次人間側の領域に移動させる。
    下まで移動させて待機させることで、タイプ 4 のペットを下に誘導させられるはず。
    人間側の領域に移動させたら、左の壁に寄せる。

    (
      下振れについてビジュアライザで確認したところ、
      下辺を作らない人間の移動開始が早すぎてタイプ 4 のペットを上に連れていってしまっていた。
      ギリギリの場所にギリギリのターンで移動させるように変更。

      改善したはずだが、スコアが逆に落ちた。多分上振れが減ってるからだと思う。
    )

    (
      いろいろやってみたら時々上手くいくようになった。
      ただ、今のところ運ゲーなので、
      下で待機してる人をランダムに移動させたり、
      壁を作り始めるタイミングを変更するといいかもしれない。

      後は、ペットが多いと人間の領域を 18 マスも取るべきではない気がする。

      また、移動量が小さいペット (1, 2, 5) は、人間の領域側に居て欲しくないので、
      これらの重みを高めにして回転量を決定するのもアリだろう。
      ただ、300T もあると正直位置はどこにでも変わり得るので、
      線引きするタイミングを遅らせて位置の変動を眺めるのが最善かもしれない。
    )

    遅くても 100 ターン程度で下の辺がほぼ完成するはず(信じてるぜ)なので、
    それ以降は
      - 途中で下の辺を締め切ってしまう
      - 左に寄せた人間が自分で領域を作って閉じこもる
    という選択肢を考慮しながら最後までシミュレートする。
  */

  // 下辺の位置を求める
  int prm = 2;
  int bottom = 18;

  // 回転させる
  int rot = 0;
  ll grv = LLONG_MAX;
  for(int i = 0; i < 4; i++){
    ll res = 0;
    // ペットの座標を回転
    for(int j = 0; j < n; j++){
      rotate90(px[j], py[j]);
    }
    // ペットごとに、座標が下辺より上なら 2^(下辺 - 位置) を res に加算する
    for(int j = 0; j < n; j++){
      if(px[j] > bottom) res += (1ll << (bottom - px[j]));
    }
    // 最小となるような回転回数を rot に求める
    if(res < grv){
      grv = res;
      rot = (i + 1) % 4;
    }
  }
  // なぜか 180 度逆転してる気がするので戻してみる。
  rot = (rot + 2) % 4;
  // rot × 90 度回転させる
  for(int i = 0; i < rot; i++){
    for(int j = 0; j < n; j++){
      rotate90(px[j], py[j]);
    }
    for(int j = 0; j < m; j++){
      rotate90(hx[j], hy[j]);
    }
  }

  // 回転回数のテスト出力
  // cout << "# " << rot << endl;
  
  // 回転回数を元にして、最終到達点までの移動距離を求める
  // doing 2d bfs from (11, 29)
  vector<vector<int>> dist(30, vector<int>(30, -1));
  vector<vector<bool>> vis(30, vector<bool>(30, false));
  queue<pair<int, int>> q;
  q.push({11, 29});
  vis[11][29] = true;
  dist[11][29] = 0;

  while(!q.empty()){
    auto p = q.front();
    q.pop();
    int x = p.first;
    int y = p.second;

    for(int i = 0; i < 4; i++){
      int dx = x + way[i][0];
      int dy = y + way[i][1];
      if(dx < 0 || dx >= 30 || dy < 0 || dy >= 30) continue;
      if(vis[dx][dy]) continue;

      dist[dx][dy] = dist[x][y] + 1;
      vis[dx][dy] = true;
      q.push({dx, dy});
    }
  }

  // 距離計算のテスト出力
  for(int i = 0; i < 30; i++){
    cout << "# ";
    for(int j = 0; j < 30; j++){
      cout << setw(2) << dist[i][j] << " ";
    }
    cout << endl;
  }

  // 下辺を作る 1 人を選ぶ = x
  vector<pair<int, int>> xsort(m);
  for(int i = 0; i < m; ++i){
    xsort[i] = {abs(bottom - hx[i]), i};
  }
  sort(all(xsort));
  int x = xsort[0].second;

  // 下辺を作る人間のモードの値
  int makerMode = hx[x] <= bottom - 1;
  if(hy[x] == 1){
    makerMode = 2;
  }
  /*
  モードの定義 : 
  0 : 下辺の位置よりひとつ上の高さまで移動する
  1 : 一番左まで移動する
  2 : 壁を作りながら右まで移動する
  3 : 壁を最後の 1 マス以外作り終え、待機している
  */
  // 次が柵を置くターンか？
  bool nextCreate = true;

  // 下辺を作らない人たちの移動先の値
  vector<int> otherMove(m, 0);
  /*
  値の定義 :
  0 : 下に移動する。
  1 : 右に移動する。
  2 : 上に移動する。
  3 : 左に移動する。
  4 : 下以外のマスを適当に選ぶ。
  */
  for(int i = 0; i < m; i++){
    if(hx[i] == 30){
      otherMove[i] = 1;
    }
  }
  for(int i = 0; i < m; i++){
    if(otherMove[i] && hy[i] == 30){
      otherMove[i] = 2;
    }
  }

  // シミュレートの開始
  for(int turn = 0; turn < 300; turn++){
    string act = "";

    for(int i = 0; i < m; i++){
      if(i == x){
        switch(makerMode){
          case 0:
            // 上に移動する
            act += "U";
            hx[i]--;
            if(hx[i] <= bottom - 1){
              makerMode = 1;
              if(hy[i] == 1){
                // 下辺を作る人間が最初から左端にいる
                makerMode = 2;
              }
            }
            break;
          case 1:
            // 左に移動する
            act += "L";
            hy[i]--;
            if(hy[i] == 1){
              makerMode = 2;
            }
            break;
          case 2:
            if(nextCreate){
              // 上から人が来ているなら待つ
              bool waitFlag = false;
              for(int j = 0; j < m; j++){
                // 自分同士は判定しないのでスキップ
                if(j == x) continue;
                if(hy[j] == hy[x]
                  && (hx[j] - (j < x) <= hx[x] + 1)
                  && otherMove[j] == 0){
                  act += ".";
                  waitFlag = true;
                  break;
                }
              }
              // ペットが配置場所やその隣接するマスにいるなら待つ
              if(!waitFlag){
                for(int j = 0; j < n; j++){
                  if(isAdjacentOrSame(px[j], py[j], hx[x] + 1, hy[x])){
                    act += ".";
                    waitFlag = true;
                    break;
                  }
                }
              }
              if(!waitFlag){
                // 人が来ていないなら壁を作る
                act += "d";
                nextCreate = false;
              }
            }else{
              act += "R";
              hy[i]++;
              nextCreate = true;
              if(hy[i] == 30){
                makerMode = 3;
              }
            }
            break;
          case 3:
            // 残り 1 マスを締めるかどうかを判定する、多分最後 30 ターンくらいでさっさと締めて良い
            if(turn < 270){
              act += ".";
            }else{
              bool waitFlag = false;
              for(int j = 0; j < n; j++){
                if(isAdjacentOrSame(px[j], py[j], hx[x] + 1, hy[x])){
                  act += ".";
                  waitFlag = true;
                  break;
                }
              }
              if(!waitFlag){
                act += "d";
              }
            }
            break;
        }
      }else{
        switch(otherMove[i]){
          case 0:
            act += "D";
            hx[i]++;
            if(hx[i] == 30){
              otherMove[i] = 1;
              if(hy[i] == 30){
                otherMove[i] = 2;
              }
            }
            break;
          case 1:
            if(269 - turn > dist[hx[i] - 1][hy[i] - 1]){
              // ランダムに生成する
              act += ".";
            }else{
              // 右に移動する
              act += "R";
              hy[i]++;
              if(hy[i] == 30){
                otherMove[i] = 2;
              }
            }
            break;
          case 2:
            if(269 - turn > dist[hx[i] - 1][hy[i] - 1]){
              // ランダムに生成する
              act += ".";
            }else{
              // 上に移動する
              act += "U";
              hx[i]--;
              if(hx[i] == hx[x]){
                otherMove[i] = 3;
              }
            }
            break;
          case 3:
            // 左に移動する
            act += "L";
            hy[i]--;
            if(hy[i] == 1){
              otherMove[i] = 4;
            }
            break;
          case 4:
            // 自分の領域を作る可能性がある
            act += ".";
            break;
        }
      }
    }
    
    // 回転量を適用した状態での出力を行う
    for(char c : act){
      cout << rotatedAct[c][rot];
    }
    cout << endl;
    // cout << act << endl;

    // 入力からペットの行動を受け取って座標を更新する
    for(int i = 0; i < n; i++){
      string pAct; cin >> pAct;
      for(char c : pAct){
        char rc = rotatedAct[c][(4 - rot) % 4];
        for(int j = 0; j < 4; j++){
          // if(rc == upStep[j]){
          if(rc == upStep[j]){
            px[i] += way[j][0];
            py[i] += way[j][1];
          }
        }
      }
    }
  }

  please give me more score return 0;
}

/*
# 全然違う方針
結構難しそうだけど、ペットを囲い込むようにして、なおかつ外の領域が連結なら、
結構なスコアが出るはずなので、それをどうにか実現したい。
*/
