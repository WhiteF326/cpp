#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  int n; cin >> n;
  vector<vector<bool>> f(n, vector<bool>(10, false));
  for(int i = 0; i < n; i++){
    for(int j = 0; j < 10; j++){
      int x; cin >> x;
      if(x) f[i][j] = true;
    }
  }
  vector<vector<int>> p(n, vector<int>(11));
  for(int i = 0; i < n; i++){
    for(int j = 0; j < 11; j++) cin >> p[i][j];
  }

  int ans = -INT_MAX;
  for(int i = 1; i < (1 << 10); i++){
    vector<int> joi(10, 0);
    for(int j = 0; j < 10; j++){
      joi[j] = (i & (1 << j) ? 1 : 0);
    }
    vector<vector<int>> q(n, vector<int>(10, 0));
    for(int j = 0; j < n; j++){
      for(int k = 0; k < 10; k++){
        if(f[j][k] && joi[k]) q[j][k]++;
      }
    }
    int res = 0;
    for(int j = 0; j < n; j++){
      res += p[j][accumulate(q[j].begin(), q[j].end(), 0)];
    }
    ans = max(ans, res);
  }
  cout << ans << endl;
}