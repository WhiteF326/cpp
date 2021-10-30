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
  vector<int> def = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
  vector<int> a(m); aryin(a, m);

  // dp[i] = マッチ棒 i 本の最大値
  auto scmp = [](string a, string b){
    if(a.length() > b.length()) return true;
    else if(a.length() < b.length()) return false;
    else return a > b;
  };
  vector<string> dp(n + 10, "");
  for(int i : a){
    dp[def[i]] = to_string(i);
  }
  for(int i = 0; i <= n; i++){
    if(!dp[i].length()) continue;
    for(int j : a){
      string tr = dp[i] + to_string(j);
      sort(all(tr), greater<char>());
      if(scmp(tr, dp[i + def[j]])){
        dp[i + def[j]] = tr;
      }
    }
  }

  cout << dp[n] << endl;
}