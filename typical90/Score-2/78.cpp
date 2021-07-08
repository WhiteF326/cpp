#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
using ll = long long;
using ld = long double;

int main(){
  int n, m; cin >> n >> m;
  vector<int> ans(n, 0);
  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    a--, b--;
    ans[max(a, b)]++;
  }
  int res = 0;
  for(int i = 0; i < n; i++){
    if(ans[i] == 1) res++;
  }
  cout << res << endl;
}