#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j)
using ll = long long;
using ld = long double;

int main(){
  ll h; cin >> h;
  ll ans = 0, ac = 0;
  while(h / pow(2, ac) >= 1){
    ans += pow(2, ac);
    ac++;
  }
  cout << ans << endl;
}