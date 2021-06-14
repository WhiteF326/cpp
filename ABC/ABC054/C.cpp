#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j);
using ll = long long;
using ld = long double;

const ll modv = 1000000007;

int main(){
  int n, m; cin >> n >> m;
  vector<vector<bool>> g(n, vector<bool>(n, false));
  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    a--, b--;
    g[a][b] = true, g[b][a] = true;
  }
  vector<int> perm(n - 1);
  for(int i = 1; i < n; i++) perm[i - 1] = i;
  int ans = 0;
  do{
    bool flg = true;
    // 1からpermを伝って向かう方法はあるか？
    int dest = 0;
    for(int i = 0; i < n - 1; i++){
      if(g[dest][perm[i]]){
        dest = perm[i];
      }else{
        flg = false;
        break;
      }
    }
    ans += flg;
  }while(next_permutation(perm.begin(), perm.end()));
  cout << ans << endl;
}