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
  int y; cin >> y;
  bool flg = false;
  if(y % 4 == 0) flg = true;
  if(y % 100 == 0) flg = false;
  if(y % 400 == 0) flg = true;
  cout << (flg ? "YES" : "NO") << endl;
}