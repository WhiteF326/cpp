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

const ll modv = 1000000007;

int n, m, q;
vector<vector<int>> req(50, vector<int>(4, 0));
int ans = 0;
vector<int> res(0);

void dfs(int p){
  res.emplace_back(p);
  if(res.size() == n){
    int pt = 0;
    for(int i = 0; i < q; i++){
      if(res[req[i][1]] - res[req[i][0]] == req[i][2]) pt += req[i][3];
    }
    ans = max(ans, pt);
    res.pop_back();
    return;
  }
  for(int i = p; i <= m; i++){
    dfs(i);
  }
  res.pop_back();
}

int main(){
  cin >> n >> m >> q;
  for(int i = 0; i < q; i++){
    cin >> req[i][0] >> req[i][1];
    req[i][0]--, req[i][1]--;
    cin >> req[i][2] >> req[i][3];
  }
  for(int i = 1; i <= m; i++){
    dfs(i);
  }
  cout << ans << endl;
}