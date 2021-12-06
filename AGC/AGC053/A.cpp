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
  string s; cin >> s;
  vector<ll> x(n + 1, 0); aryin(x, n + 1);
  
  vector<ll> diff(n, LLONG_MAX);
  for(int i = 0; i < n; i++){
    diff[i] = abs(x[i] - x[i + 1]);
  }

  int v = *min_element(all(diff));

  cout << v << endl;

  for(int i = 0; i < v; i++){
    for(int j = 0; j < n + 1; j++){
      cout << x[j] / v + (x[j] % v > i ? 1 : 0) << " ";
    }cout << endl;
  }
}