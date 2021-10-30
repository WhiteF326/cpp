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

  vector<ll> a(n + 1, 0), b(n + 1, 0);
  for(int i = 0; i < n; i++){
    cin >> a[i + 1] >> b[i + 1];
  }
  auto anslist = convolution_ll(a, b);
  for(int i = 1; i <= 2 * n; i++){
    cout << anslist[i] << endl;
  }
}