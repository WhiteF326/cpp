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
  int n, s; cin >> n >> s;
  vector<pair<int, int>> ab(n);
  for(int i = 0; i < n; i++){
    cin >> ab[i].first >> ab[i].second;
  }

  vector<vector<int>> dp(n + 1, vector<int>(100001, 0));
  dp[1][ab[0].first] = 1;
  dp[1][ab[0].second] = 2;
  for(int i = 1; i < n; i++){
    for(int j = 0; j <= 100000; j++){
      if(dp[i][j]){
        // A を買う
        dp[i + 1][min(100000, j + ab[i].first)] = 1;
        // B を買う
        dp[i + 1][min(100000, j + ab[i].second)] = 2;
      }
    }
  }

  if(dp[n][s]){
    int cur = s;
    string path = "";
    for(int i = n; i >= 1; i--){
      if(dp[i][cur] == 1){
        path += "A";
        cur -= ab[i - 1].first;
      }else{
        path += "B";
        cur -= ab[i - 1].second;
      }
    }
    reverse(all(path));
    cout << path << endl;
  }else{
    cout << "Impossible" << endl;
  }
}