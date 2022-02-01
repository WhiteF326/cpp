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


#define mint modint998244353
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n, k; cin >> n >> k;
  vector<vector<int>> p(n, vector<int>(n, 0));
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++) cin >> p[i][j];
  }

  dsu h(n), v(n);
  // check horizontally
  for(int i = 0; i < n - 1; i++){
    for(int j = i + 1; j < n; j++){
      // check for i, j
      bool rev = true;
      for(int d = 0; d < n; d++){
        if(p[d][i] + p[d][j] > k) rev = false;
      }
      if(rev){
        h.merge(i, j);
      }
    }
  }
  // check vertically
  for(int i = 0; i < n - 1; i++){
    for(int j = i + 1; j < n; j++){
      // check for i, j
      bool rev = true;
      for(int d = 0; d < n; d++){
        if(p[i][d] + p[j][d] > k) rev = false;
      }
      if(rev){
        v.merge(i, j);
      }
    }
  }
  
  // factorization list
  vector<mint> fcl(51, 1);
  for(int i = 2; i <= 50; i++){
    fcl[i] = fcl[i - 1] * i;
  }
  
  mint ans = 1;
  for(auto s : h.groups()){
    ans *= fcl[s.size()];
  }
  for(auto s : v.groups()){
    ans *= fcl[s.size()];
  }
  
  cout << ans.val() << endl;
}