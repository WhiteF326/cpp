#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j);
using ll = long long;
using ld = long double;

int main(){
  int n; cin >> n;
  vector<int> a(n), b(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < n; i++) cin >> b[i];

  int ans = 0;
  for(int i = 0; i < n; i++){
    int res = 0;
    for(int j = 0; j <= i; j++) res += a[j];
    for(int j = i; j < n; j++) res += b[j];
    ans = max(ans, res);
  }
  cout << ans << endl;
}