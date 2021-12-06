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
  int r, c; cin >> r >> c;

  auto toPos = [&](int x, int y){
    return y * c + x;
  };
  vector<vector<pair<int, int>>> g(r * c);
  for(int i = 0; i < r; i++){
    for(int j = 0; j < c - 1; j++){
      int a; cin >> a;
      g[toPos(j, i)].push_back({toPos(j + 1, i), a});
      g[toPos(j + 1, i)].push_back({toPos(j, i), a});
    }
  }
  for(int i = 0; i < r - 1; i++){
    for(int j = 0; j < c; j++){
      int b; cin >> b;
      g[toPos(j, i)].push_back({toPos(j, i + 1), b});
    }
  }

  // 
}