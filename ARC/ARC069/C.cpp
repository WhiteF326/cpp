#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
using ll = long long;
using ld = long double;

int main(){
  ll n, m; cin >> n >> m;
  ll ans = 0;

  // step1 今あるSを使いきれるか？
  ans += min(n, m / 2);
  m -= ans * 2;
  if(m < 2){
    cout << ans << endl;
    return 0;
  }

  // step2 m / 4を足して答え
  ans += m / 4;
  cout << ans << endl;
}