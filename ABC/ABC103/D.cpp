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

int main(){
  int n, m; cin >> n >> m;
  vector<pair<int, int>> ab(m, pair<int, int>());
  for(int i = 0; i < m; i++){
    cin >> ab[i].first >> ab[i].second;
  }
  sort(all(ab), greater<pair<int, int>>());

  int ans = 0;
  int p = INT_MAX;
  for(int i = 0; i < m; i++){
    if(p >= ab[i].second){
      ans++;
      p = ab[i].first;
    }
  }
  cout << ans << endl;
}