#include <bits/stdc++.h>
using namespace std;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  ll p, q, r; cin >> p >> q >> r;
  ll k; cin >> k;
  vector<ll> x(k + 1);
  x[0] = p, x[1] = q, x[2] = r;
  for(int i = 3; i <= k; i++){
    x[i] = (x[i - 1] + x[i - 2] + x[i - 3]) % 10;
  }
  for(int i = 0; i <= k; i++){
    if(x[i] % 10 == 3) cout << i + 1 << endl;
  }
}