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
  int n; cin >> n;
  vector<pair<int, int>> a(n);
  for(int i = 0; i < n; i++) cin >> a[i].first, a[i].second = i + 1;

  sort(all(a));
  reverse(all(a));

  for(int i = 0; i < n; i++){
    cout << a[i].second << endl;
  }
}