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

#define vvvi vector<vector<vector<int>>>
#define vvi vector<vector<int>>
#define vi vector<int>

int main(){
  int n, m; cin >> n >> m;
  vector<pair<int, int>> pl(m);
  vector<vector<int>> q(n + 1);
  for(int i = 0; i < m; i++){
    int p, y; cin >> p >> y;
    q[p].push_back(y);
    pl[i] = mp(p, y);
  }

  for(int i = 0; i < n; i++) sort(all(q[i + 1]));

  for(int i = 0; i < m; i++){
    int li = upper_bound(all(q[pl[i].first]), pl[i].second) - q[pl[i].first].begin();
    printf("%06d%06d\n", pl[i].first, li);
  }
}