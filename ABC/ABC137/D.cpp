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

int main(){
  int n, m; cin >> n >> m;
  vector<vector<int>> qu(100001, vector<int>(0));
  for(int i = 0; i < n; i++){
    int a, b; cin >> a >> b;
    qu[a].push_back(b);
  }

  priority_queue<int> q;
  int ans = 0;
  for(int i = 1; i <= m; i++){
    for(int b : qu[i]) q.push(b);
    if(!q.empty()){
      ans += q.top();
      q.pop();
    }
  }
  cout << ans << endl;
}