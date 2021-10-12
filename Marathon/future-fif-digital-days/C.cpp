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


const int wy[] = {-1, 1, 0, 0};
const int wx[] = {0, 0, -1, 1};

int main(){
  int n, k, b; cin >> n >> k >> b;
  ofstream ofs("out.txt");
  vector<vector<int>> sr(k, vector<int>(2, 0));
  vector<vector<int>> stg(n, vector<int>(n, 0));
  int sth, stw;
  for(int i = 0; i < k; i++){
    int h, w; cin >> h >> w;
    sr[i][0] = h, sr[i][1] = w;
    sth = h, stw = w;
    stg[h][w] = 1;
  }

  dsu d(n * n);
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

  // コストの降順に有効ならば置こうとする
  vector<pair<double, int>> putwait;
  vector<pair<int, int>> infl(250000);
  int p = 0;
  vector<vector<int>> anslist(n, vector<int>(n, 0));
  for(int mi = 1; mi < b; mi++){
    for(int i = 0; i < n - bh[mi]; i++){
      for(int j = 0; j < n - bw[mi]; j++){
        int ctr = 0;
        for(int y = 0; y < bh[mi]; y++){
          for(int x = 0; x < bw[mi]; x++){
            if(pol[mi][y][x]){
              if(stg[i + y][j + x]) ctr++;
            }
          }
        }
        if(ctr){
          putwait.emplace_back(mp(ctr / (double)cost[mi], p));
          infl[p] = mp(i * n + j, mi);
          p++;
        }
      }
    }
  }

  vector<vector<int>> visited(n, vector<int>(n, 0));
  sort(all(putwait), [](pair<double, int> a, pair<double, int> b){
    return a.first > b.first;
  });

  for(auto p : putwait){
    // 既に置けなくなっているか？
    bool flg = false;
    int m = infl[p.second].second;
    int h = infl[p.second].first / n;
    int w = infl[p.second].first % n;
    for(int y = 0; y < bh[m]; y++){
      for(int x = 0; x < bw[m]; x++){
        if(pol[m][y][x]){
          if(visited[h + y][w + x]) flg = true;
        }
      }
    }
    if(!flg){
      // 置く
      anslist[h][w] = m + 1;
      for(int y = 0; y < bh[m]; y++){
        for(int x = 0; x < bw[m]; x++){
          if(pol[m][y][x]){
            visited[h + y][w + x]++;
            d.merge(h * n + w, (h + y) * n + w + x);
          }
        }
      }
    }
  }


  int ans = 0;
  queue<int> a;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(anslist[i][j]){
        ans++;
        a.push(anslist[i][j]);
        a.push(i);
        a.push(j);
      }
    }
  }

  printf("%d\n", ans);
  ofs << ans << endl;
  while(!a.empty()){
    printf("%d ", a.front()); ofs << a.front() << " "; a.pop();
    printf("%d ", a.front()); ofs << a.front() << " "; a.pop();
    printf("%d\n", a.front()); ofs << a.front() << endl; a.pop();
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cout << visited[i][j];
    }cout << endl;
  }
}