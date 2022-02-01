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


ll x;
ll res = 0;
set<ll> st;
void dfs(int d, int diff){
  res = res * 10 + d;
  if(res >= x){
    st.insert(res);
    res /= 10;
    return;
  }
  int nd = d + diff;
  if(0 <= nd && nd <= 9){
    dfs(nd, diff);
  }
  res /= 10;
}
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  cin >> x;
  // int n = to_string(x).length();
  // ll xx = x;
  // vector<int> digits(n, 0);
  // for(int i = 0; i < n; i++){
  //   digits[n - i - 1] = x % 10;
  //   x /= 10;
  // }

  for(int i = 0; i <= 9; i++){
    for(int j = -9; j <= 9; j++){
      if(i || j) dfs(i, j);
    }
  }

  cout << *st.begin() << endl;
}