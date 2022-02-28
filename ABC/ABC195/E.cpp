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
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n; cin >> n;
  string s, x; cin >> s >> x;

  vector<vector<bool>> dp(n + 1, vector<bool>(7, 0));
  dp[0][0] = 1;

  reverse(all(s));
  reverse(all(x));

  for(int i = 0; i < n; i++){
    int d = s[i] - '0';
    if(x[i] == 'T'){
      for(int j = 0; j < 7; j++){
        if(dp[i][(j * 10 + d) % 7] || dp[i][(j * 10) % 7]){
          dp[i + 1][j] = true;
        }
      }
    }else{
      for(int j = 0; j < 7; j++){
        if(dp[i][(j * 10 + d) % 7] && dp[i][(j * 10) % 7]){
          dp[i + 1][j] = true;
        }
      }
    }
  }

  if(dp[n][0]){
    cout << "Takahashi" << endl;
  }else{
    cout << "Aoki" << endl;
  }
}
