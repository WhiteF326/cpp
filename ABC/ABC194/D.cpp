#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
using ll = long long;
using ld = long double;

int main(){
  int n; cin >> n;
  ld ans = 0;
  for(int i = n; i > 1; i--){
    ld apx = (i - 1) / (ld)n;
    ans += 1.0 / apx;
  }
  cout << fs(12) << ans << endl;
}