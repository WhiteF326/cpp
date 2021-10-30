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
  int n, c; cin >> n >> c;
  vector<vector<ll>> costs(c, vector<ll>(c, 0));
  for(int i = 0; i < c; i++){
    for(int j = 0; j < c; j++) cin >> costs[i][j];
  }

  vector<map<int, ll>> vl(3);
  for(int i = 0; i < 3; i++) for(int j = 0; j < c; j++) vl[i][j] = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      int x; cin >> x;
      vl[(i + j + 2) % 3][x - 1]++;
    }
  }

  ll ans = LLONG_MAX;
  for(int i = 0; i < c; i++){
    for(int j = 0; j < c; j++){
      for(int k = 0; k < c; k++){
        if(i == j || j == k || i == k) continue;
        ll cost = 0;
        // 0 -> i, 1 -> j, 2 -> k
        for(int t = 0; t < c; t++){
          cost += costs[t][i] * vl[0][t];
        }
        for(int t = 0; t < c; t++){
          cost += costs[t][j] * vl[1][t];
        }
        for(int t = 0; t < c; t++){
          cost += costs[t][k] * vl[2][t];
        }
        ans = min(ans, cost);
      }
    }
  }
  cout << ans << endl;
}