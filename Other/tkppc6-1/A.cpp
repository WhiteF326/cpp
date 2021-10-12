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


int main(){
  int n; cin >> n;
  if(n == 2015) cout << 1 << endl;
  else if(n == 2016) cout << 2 << endl;
  else if(n == 2017) cout << -1 << endl;
  else if(n >= 2018) cout << n - 2015 << endl;
  else cout << -1 << endl;
  //
}