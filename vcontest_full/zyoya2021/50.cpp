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
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n, m; cin >> n >> m;
  set<int> st;
  for(int i = 0; i < m; i++){
    int a; cin >> a;
    st.insert(a);
  }

  vector<mint> dp(n + 1000, 0);
  dp[0] = 1;
  for(int i = 0; i <= n; i++){
    if(st.find(i + 1) == st.end()) dp[i + 1] += dp[i];
    if(st.find(i + 2) == st.end()) dp[i + 2] += dp[i];
  }

  cout << dp[n].val() << endl;
}