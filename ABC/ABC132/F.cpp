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


#define mint modint1000000007
ostream& operator<< (ostream& os, const mint& v){
  os << v.val();
  return os;
}

int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  ll n; cin >> n;
  int k; cin >> k;

  map<ll, ll> ranges;
  for(ll i = 1; i <= n; i++){
    ll left = floor(n / (ld)i);
    ll right = ceil(n / (ld)(i + 1));
    if(n % (i + 1) == 0) right++;

    ranges[i] = left - right + 1;

    if(right - 1 == 0){
      break;
    }else{
      i = n / (right - 1) - 1;
    }
  }

  int m = ranges.size();
  vector<ll> rlis(0);
  for(auto e : ranges){
    rlis.push_back(e.second);
  }

  vector<vector<mint>> dp(k + 1, vector<mint>(m, 0));
  dp[0][0] = 1;

  for(int i = 0; i < k; i++){
    mint sum = 0;
    for(int j = 0; j < m; j++){
      sum += dp[i][j] * rlis[m - j - 1];
      dp[i + 1][m - j - 1] = sum;
    }
  }

  mint ans = 0;
  for(int i = 0; i < m; i++){
    ans += dp[k][i] * rlis[m - i - 1];
  }
  cout << ans << endl;
}