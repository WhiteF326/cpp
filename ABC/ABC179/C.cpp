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
  int n; cin >> n;
  // cには何でも入る
  ll ans = 0;
  for(int a = 1; a < n; a++){
    ans += (n - 1) / a;
  }
  cout << ans << endl;
}
