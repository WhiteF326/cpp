#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define const constexpr
#define pdesc(t) t, vector<t>, greater<t>
#define tg(a, b) get<a>(b)
using ll = long long;
using ld = long double;

const ll modv = 1000000007;
// {x, y} "LURD"
vector<vector<int>> way = {
  {-1, 0},
  {0, -1},
  {1, 0},
  {0, 1}
};
string wayst = "LURD";
template <typename T>
int matrixsum(vector<vector<T>> mtrx){
  int ans = 0;
  for(vector<T> arr : mtrx){
    ans += accumulate(arr.begin(), arr.end(), 0);
  }
  return ans;
}

int main(){
  int ti = clock();
  //clock() - ti < 18 * CLOCKS_PER_SEC / 10
  int n; cin >> n;
  int si, sj; cin >> si >> sj;

  vector<vector<int>> stage(n, vector<int>(n));
  vector<vector<int>> f(n, vector<int>(n, 0));
  vector<vector<int>> yd(n, vector<int>(1, -1)), td(n, vector<int>(1, -1));
  for(int i = 0; i < n; i++){
    string c; cin >> c;
    for(int j = 0; j < n; j++){
      if(c[j] == '#'){
        stage[i][j] = -1;
        yd[i].push_back(j);
        td[j].push_back(i);
      }else{
        stage[i][j] = c[j] - '0';
      }
    }
  }
  for(int i = 0; i < n; i++){
    yd[i].push_back(n);
    td[i].push_back(n);
  }
  // score, si, sj, time, way
  priority_queue<tuple<int, int, int, int, string>> q;
  priority_queue<tuple<int, int, int, int, string>> e;
  q.push(make_tuple(0, si, sj, 0, ""));
  
  while(clock() - ti < 20 * CLOCKS_PER_SEC / 10){
    auto pos = q.top();
    int mi = si, mj = sj, mt = tg(3, pos);
    string mw = tg(4, pos);

    for(int v = 0; v < 4; v++){
      int res = 0;
      if(v % 2){
        // yd[mi]をmjで検索
        int pos = lower_bound(all(yd[mi]), mj) - yd[mi].begin();
        res = yd[mi][pos + 1] - yd[mi][pos] - 1;
      }else{
        // td[mj]をmiで検索
        int pos = lower_bound(all(td[mj]), mi) - td[mj].begin();
        res = td[mi][pos + 1] - td[mi][pos] - 1;
      }
      int ft = 0;
      while(true){
        bool flg = false;
        for(int hoge = 0; hoge < 2; hoge++){
          mi += way[v][0], mj += way[v][1];
          if(stage[mi][mj] < 0 || mi < 0 || mi >= n || mj < 0 || mj >= n){
            mi -= way[v][0], mj -= way[v][1];
            flg = true;
            break;
          }
          mt += stage[mi][mj];
          ft += stage[mi][mj];
          mw.push_back(wayst[v]);
        }
        if(flg){
          e.push(make_tuple(tg(0, pos) + res, mi, mj, mt, mw));
          break;
        }
        q.push(make_tuple(tg(0, pos) / ft, mi, mj, mt, mw));
      }
    }
  }
  cout << tg(4, q.top()) << endl;
  return 0;
}