// refactoring for blog
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  int n, m; cin >> n >> m;
  vector<vector<int>> sl(m, vector<int>(0));
  for(int i = 0; i < m; i++){
    int k; cin >> k;
    for(int j = 0; j < k; j++){
      int s; cin >> s;
      sl[i].emplace_back(s - 1);
    }
  }
  vector<int> p(m);
  for(int i = 0; i < m; i++) cin >> p[i];

  int ans = 0;
  for(int i = 0; i < (1 << n); i++){
    int light = 0;
    for(int j = 0; j < m; j++){
      int res = 0;
      for(int k : sl[j]) if(i & (1 << k)) res++;
      if(res % 2 == p[j]) light++;
    }
    if(light == m) ans++;
  }
  cout << ans << endl;
}