#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j);
using ll = long long;
using ld = long double;

const ll modv = 1000000007;

int main(){
  int k; cin >> k;
  ll ans = 0;
  for(int a = 1; a <= k; a++){
    for(int b = 1; b <= k / a; b++){
      ans += k / (a * b);
    }
  }
  cout << ans << endl;
}
