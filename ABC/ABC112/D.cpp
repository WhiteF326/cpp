#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  int n, m; cin >> n >> m;
  // mの約数しかあり得ない
  int ans = 0;
  for(int i = 1; i <= (int)sqrt(m); i++){
    if(n <= m / i && m % i == 0) ans = max(i, ans);
    if(n <= i && m % i == 0) ans = max(m / i, ans);
  }
  cout << ans << endl;
}