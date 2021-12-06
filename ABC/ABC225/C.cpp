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
  int n, m; cin >> n >> m;
  vector<vector<ll>> stg(n, vector<ll>(7, 0));
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++) cin >> stg[i][j];
  }

  // 余りが単調増加?
  auto lm = [](ll a){
    if(a % 7) return a % 7;
    else return 7LL;
  };

  ll start = stg[0][0];
  for(int i = 0; i < n; i++){
    for(int j = 0; j < 7; j++){
      if(stg[i][j] && start != stg[i][j]){
        cout << "No" << endl;
        return 0;
      }
      start++;
    }
  }

  for(int i = 0; i < m - 1; i++){
    if(lm(stg[0][i]) >= lm(stg[0][i + 1])){
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
}