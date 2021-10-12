#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define const constexpr
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;
#define query(t) for(int _ = 0; _ < t; _++)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];
#define ver first
#define hor second

// 上下左右
const int wy[] = {-1, 1, 0, 0};
const int wx[] = {0, 0, -1, 1};

int main(){
  // 入力パート
  int n, k, b; cin >> n >> k >> b;
  ofstream ofs("out.txt");
  vector<vector<int>> sr(k, vector<int>(2, 0));
  int sth, stw;
  for(int i = 0; i < k; i++){
    int h, w; cin >> h >> w;
    sr[i][0] = h, sr[i][1] = w;
    sth = h, stw = w;
  }
  vector<int> bh(b), bw(b), cost(b);
  vector<vector<vector<int>>> pol(b);
  for(int i = 0; i < b; i++){
    int h, w, c; cin >> h >> w >> c;
    bh[i] = h, bw[i] = w, cost[i] = c;
    vector<vector<int>> st(h, vector<int>(w));
    for(int j = 0; j < h; j++){
      string s; cin >> s;
      for(int l = 0; l < w; l++){
        st[j][l] = s[l] == '#';
      }
    }
    pol[i] = st;
  }

  // ミノの 4 方向にある端点を取得

  vector<vector<int>> minp(b, vector<int>(4, 0));
  for(int i = 0; i < b; i++){
    // 縦
    for(int h = 0; h < bh[i]; h++){
      if(pol[i][h][0]) minp[i][2] = h;
      if(pol[i][h][bw[i] - 1]) minp[i][3] = h;
    }
    // 横
    for(int w = 0; w < bw[i]; w++){
      if(pol[i][0][w]) minp[i][0] = w;
      if(pol[i][bh[i] - 1][w]) minp[i][1] = w;
    }
  }

  // 左から右、上から下における縦、横の変動量
  vector<pair<int, int>> diff(b);
  for(int i = 0; i < b; i++){
    diff[i].ver = minp[i][3] - minp[i][2];
    diff[i].hor = minp[i][1] - minp[i][0];
  }

  // bfs する
  
  queue<int> q;
  q.push(sth * n + stw);
  vector<vector<int>> before(n, vector<int>(n, -1));
  vector<vector<bool>> visited(n, vector<bool>(n, false));
  visited[sth][stw] = true;
 
  while(!q.empty()){
    int dest = q.front();
    q.pop();
 
    int y = dest / n, x = dest % n;
 
    for(int d = 0; d < 4; d++){
      int dy = y + wy[d], dx = x + wx[d];
      if(dy >= 0 && dy < n && dx >= 0 && dx < n){
        if(!visited[dy][dx]){
          visited[dy][dx] = true;
          before[dy][dx] = dest;
          q.push(dy * n + dx);
        }
      }
    }
  }

  vector<vector<int>> pln(n, vector<int>(n, 0));
  vector<vector<int>> anslist(n, vector<int>(n, -1));
  vector<vector<bool>> filled(n, vector<bool>(n, false));
  anslist[sth][stw] = sth * n + stw;

  // 各頂点について経路復元
  for(int i = 0; i < k - 1; i++){
    int cury = sr[i][0], curx = sr[i][1];

    while(before[cury][curx] != -1){
      pln[cury][curx] = 1;
      anslist[cury][curx] = cury * n + curx;
      filled[cury][curx] = 1;
      int bf = before[cury][curx];
      cury = bf / n, curx = bf % n;
    }
  }

  // ミノごとに置き換えをテスト
  for(int i = 2; i < b; i++){
    // for(int i = 0; i < n; i++){
    //   for(int j = 0; j < n; j++){
    //     printf("%03d", anslist[i][j]);
    //   }cout << endl;
    // }
    for(int h = 0; h < n - bh[i - 1]; h += bh[i - 1]){
      for(int w = 0; w < n - bw[i - 1]; w++){
        int nd = floor(cost[i - 1] / 50.0);
        for(int y = 0; y < bh[i - 1]; y++){
          for(int x = 0; x < bw[i - 1]; x++){
            nd -= filled[h + y][w + x];
          }
        }

        // 置き換えるか？
        if(nd > 0) continue;
        pln[h][w] = i;
          
        // 重なるミノを消す
        for(int y = 0; y < bh[i - 1]; y++){
          for(int x = 0; x < bw[i - 1]; x++){
            if(filled[h + y][w + x]){
              // 重なる
              int pary = anslist[h + y][w + x] / n, parx = anslist[h + y][w + x] % n;
              // 消す
              for(int dy = 0; dy < bh[pln[pary][parx]]; dy++){
                for(int dx = 0; dx < bw[pln[pary][parx]]; dx++){
                  if(pol[pln[pary][parx]][dy][dx]){
                    filled[h + dy][w + dx] = false;
                    anslist[h + dy][w + dx] = -1;
                    pln[h + dy][w + dx] = 0;
                  }
                }
              }
            }
          }
        }

        // 配置する
        for(int y = 0; y < bh[i - 1]; y++){
          for(int x = 0; x < bw[i - 1]; x++){
            if(pol[i - 1][y][x]){
              filled[h + y][w + x] = true;
              anslist[h + y][w + x] = h * n + w;
            }
          }
        }
      }
    }
  }
  
  // 出力データ化

  int ans = 0;
  queue<int> a;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(pln[i][j]){
        ans++;
        a.push(pln[i][j]);
        a.push(i);
        a.push(j);
      }
    }
  }

  // 出力

  // printf("%d\n", ans);
  ofs << ans << endl;
  while(!a.empty()){
    // printf("%d ", a.front());
    ofs << a.front() << " ";
    a.pop();

    // printf("%d ", a.front());
    ofs << a.front() << " ";
    a.pop();
    
    // printf("%d\n", a.front());
    ofs << a.front() << endl;
    a.pop();
  }
}