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
#define chmin(a, b) a = min(a, b)


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int h, n; cin >> h >> n;
  vector<pair<int, int>> m(n);
  for(int i = 0; i < n; i++){
    cin >> m[i].first >> m[i].second;
  }

  vector<int> dp(h + 1, INT_MAX);
  dp[0] = 0;
  for(int i = 1; i <= h; i++){
    for(int j = 0; j < n; j++){
      chmin(dp[i], dp[max(0, i - m[j].first)] + m[j].second);
    }
  }
  cout << dp[h] << endl;
}