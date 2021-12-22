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


int main(){
  int h, w; cin >> h >> w;
  vector<vector<int>> stage(h, vector<int>(w, 0));
  for(int i = 0; i < h; i++){
    string s; cin >> s;
    for(int j = 0; j < w; j++){
      stage[i][j] = s[j] == '#';
    }
  }

  deque<int> q;
  q.push_front(0);
  vector<vector<bool>> visited(h, vector<bool>(w, 0));
  visited[0][0] = 1;
  vector<vector<int>> depth(h, vector<int>(w, INT_MAX));
  depth[0][0] = 1;

  while(!q.empty()){
    int dest = q.front();
    q.pop_front();

    
  }
}