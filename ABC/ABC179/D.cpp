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

ll modv = 998244353;

int main(){
  int n, k; cin >> n >> k;
  vector<pair<ll, ll>> lr(k);
  for(int i = 0; i < k; i++){
    int l, r; cin >> l >> r;
    lr[i] = mp(l, r);
  }

  vector<ll> dp(n, 0), sdp(n + 1, 0);
  dp[0] = 1, sdp[1] = 1;

  for(int i = 1; i < n; i++){
    for(auto p : lr){
      ll l = max(0LL, i - p.second), r = max(0LL, i - p.first + 1);
      dp[i] = (dp[i] + sdp[r] - sdp[l] + 2 * modv) % modv;
    }
    sdp[i + 1] = (sdp[i] + dp[i]) % modv;
  }

  cout << dp[n - 1] << endl;
}