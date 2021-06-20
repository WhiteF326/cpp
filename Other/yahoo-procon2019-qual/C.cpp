#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
using ll = long long;
using ld = long double;

int main(){
  ll k, a, b; cin >> k >> a >> b;
  // b - a が1以下なら1 + k
  if(b - a <= 1){
    cout << 1 + k << endl;
  }else{
    ll ans = 0;
    k = k - a + 1LL;      // 最初の一枚補正してa枚にする
    ans += (k / 2) * (b - a);
    ans += k % 2;
    cout << ans + a << endl;
  }
}