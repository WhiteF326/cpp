#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


vector<int> wx = {-1, 0, 0, 1};
vector<int> wy = {0, -1, 1, 0};

vector<int> v(36, INT_MAX);
int h, w;

int ans = INT_MAX;

void dfs(int t){
  if(t > 24){
    return;
  }
  bool comp = 1;
  int zr = 0;
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      if(i == h - 1 && j == w - 1) continue;
      if(v[i * w + j] != (i * w + j + 1)) comp = 0;
      if(v[i * w + j] == 0){
        zr = i * w + j;
      }
      // cout << v[i * w + j] << " ";
    }
    // cout << endl;
  }

  if(comp){
    ans = min(ans, t);
    return;
  }

  int zx = zr % w, zy = zr / w;
  for(int i = 0; i < 4; i++){
    int cx = zx + wx[i], cy = zy + wy[i];
    cout << cx <<" " << cy << endl;
    if(cy < 0 || cy >= h || cx < 0 || cx >= w) continue;

    swap(v[zr], v[cy * w + cx]);
    dfs(t + 1);
    swap(v[zr], v[cy * w + cx]);
  }
}

int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  cin >> h >> w;
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      cin >> v[i * w + j];
    }
  }

  dfs(0);

  cout << ans << endl;
}