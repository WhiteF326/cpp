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
  vector<int> a(n); aryin(a, n);

  vector<int> b(all(a));
  sort(all(b));
  b.erase(unique(all(b)), b.end());

  for(int i = 0; i < n; i++) cout << lower_bound(all(b), a[i]) - b.begin() << endl;
}