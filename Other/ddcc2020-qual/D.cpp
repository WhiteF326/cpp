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
  int m; cin >> m;

  ll dl = 0, s = 0;
  for(int i = 0; i < m; i++){
    ll d, c; cin >> d >> c;
    dl += c;
    s += d * c;
  }
  cout << (dl - 1) + (s - 1) / 9 << endl;
}