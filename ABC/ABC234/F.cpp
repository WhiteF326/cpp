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


#define mint modint998244353
struct pascalComb{
  vector<vector<mint>> f;
  int size;
  
  pascalComb(int size){
    this->size = size;

    f.resize(size + 5);
    for(int i = 0; i <= size; i++) f[i].resize(size + 5);
    f[0][0] = 1;
    for(int i = 1; i <= size; i++){
      f[i][0] = 1;
      for(int j = 1; j <= size; j++){
        f[i][j] = f[i - 1][j - 1] + f[i - 1][j];
      }
    }
  }

  mint C(int n, int r){
    assert(n <= this->size);
    assert(r <= this->size);
    assert(r <= n);
    
    return f[n][r];
  }
};
#define al 26
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  string s; cin >> s;
  int n = s.length();

  vector<int> c(26, 0);
  for(char v : s) c[v - 'a']++;

  pascalComb pc(n + 200);

  vector<vector<mint>> dp(al + 1, vector<mint>(n + 1, 0));
  dp[0][0] = 1;

  for(int i = 0; i < al; i++){
    for(int j = 0; j <= n; j++){
      for(int k = 0; k <= min(c[i], j); k++){
        dp[i + 1][j] += dp[i][j - k] * pc.C(j, k);
      }
    }
  }

  mint ans = 0;
  for(int i = 1; i <= n; i++){
    ans += dp[26][i];
  }cout << ans.val() << endl;
}