#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define const constexpr
#define pdesc(t) t, vector<t>, greater<t>
#define chmin(a, b) a = min(a, b)
using ll = long long;
using ld = long double;

int n, a, b, c;
vector<int> l(8);
int ans = INT_MAX;

int dfs(int point){
  //
}

int main(){
  cin >> n >> a >> b >> c;
  for(int i = 0; i < n; i++) cin >> l[i];
  
  sort(all(l));
  
  cout << ans << endl;
}