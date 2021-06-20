#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  int n, x; cin >> n >> x;
  int p = 0;
  int ans = 1;
  for(int i = 0; i < n; i++){
    int d; cin >> d;
    p += d;
    if(p <= x) ans++;
    else break;
  }
  cout << ans << endl;
}