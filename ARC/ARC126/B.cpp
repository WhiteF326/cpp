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
#define query(t) for(int _ = 0; _ < t; _++)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];

#define pii pair<int, int>


int main(){
  int n, m; cin >> n >> m;

  vector<pair<int, int>> lines(m);
  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    lines[i] = mp(a, b);
  }

  sort(all(lines));
}