#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j)
using ll = long long;
using ld = long double;

int main(){
  int n; cin >> n;
  vector<int> v(n);
  for(int i = 0; i < n; i++) cin >> v[i];
  for(int i = 0; i < n; i++){
    int c; cin >> c;
    v[i] -= c;
  }
  int ans = 0;
  for(int i = 0; i < n; i++) if(v[i] > 0) ans += v[i];
  cout << ans << endl;
}