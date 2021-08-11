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
  int h, w, m; cin >> h >> w >> m;
  vector<pair<int, int>> pos(m);
  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    pos[i] = mp(a, b);
  }
  map<int, int> hl, wl;
  
}