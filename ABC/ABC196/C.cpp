#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j);
using ll = long long;
using ld = long double;

int main(){
  ll n; cin >> n;
  ll ans = 0;
  for(int i = 1; i <= (int)sqrt(n); i++){
    ll d = (i * pow(10, ceil(log10(i + 1)))) + i;
    if(d <= n) ans++;
  }
  cout << ans << endl;
}