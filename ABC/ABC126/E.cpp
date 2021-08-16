#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define const constexpr
#define pdesc(t) t, vector<t>, greater<t>
#define chmin(a, b) a = min(a, b)
using ll = long long;
using ld = long double;

int main(){
  int n, m; cin >> n >> m;
  vector<tuple<int, int, int>> c(m);
  for(int i = 0; i < m; i++){
    int x, y, z; cin >> x >> y >> z;
    c[i] = {x, y, z};
  }
  
  // dp[i][j] = i個目
}