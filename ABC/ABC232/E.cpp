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


const ll modv = 998244353;
int main(){
  ll h, w, k; cin >> h >> w >> k;

  vector<vector<ll>> dp(k + 1, vector<ll>(4, 0));
  // 完全に同じマス、同じ行、同じ列、そうでないもの
  dp[0][0] = 1;

  for(int i = 1; i <= k; i++){
    //
    dp[i][0] = ((dp[i - 1][1] * (w - 1) % modv) + (dp[i - 1][2] * (h - 1) % modv)) % modv;
    //
    dp[i][1] = (((dp[i - 1][1] * (w - 2)) % modv) + ((dp[i - 1][3] * (h - 1)) % modv) + dp[i - 1][0]) % modv;
    dp[i][2] = (((dp[i - 1][2] * (h - 2)) % modv) + ((dp[i - 1][3] * (w - 1)) % modv) + dp[i - 1][0]) % modv;
    //
    dp[i][3] = ((dp[i - 1][3] * (h - 2) % modv) + (dp[i - 1][3] * (w - 2) % modv)) % modv;
    dp[i][3] = (dp[i][3] + dp[i - 1][1] + dp[i - 1][2]) % modv;
  }

  int x, y, cx, cy;
  cin >> x >> y >> cx >> cy;
  if(x == cx && y == cy){
    cout << dp[k][0] << endl;
  }else if(x == cx){
    cout << dp[k][1] << endl;
  }else if(y == cy){
    cout << dp[k][2] << endl;
  }else{
    cout << dp[k][3] << endl;
  }
}