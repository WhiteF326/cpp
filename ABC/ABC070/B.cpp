#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j)
using ll = long long;
using ld = long double;

int main(){
  int a, b, c, d; cin >> a >> b >> c >> d;
  int ans = 0;
  for(int i = 0; i <= 100; i++){
    if(a <= i && i < b && c <= i && i < d) ans++;
  }
  cout << ans << endl;
}