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


int n;
vector<int> a(10);
vector<int> x(10);
int ans = 0;
void dfs(int diff, int depth){
  x[depth] = diff + a[depth];
  if(depth == n - 1){
    int res = 1;
    for(int i = 0; i < n; i++){
      res *= x[i];
    }
    if(res % 2 == 0){
      ans++;
    }
    return;
  }else{
    for(int i = -1; i <= 1; i++){
      dfs(i, depth + 1);
    }
  }
}

int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  cin >> n;
  aryin(a, n);

  dfs(-1, 0);
  dfs(0, 0);
  dfs(1, 0);

  cout << ans << endl;
}