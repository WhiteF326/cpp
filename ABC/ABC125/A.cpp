#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
using ll = long long;
using ld = long double;

int main(){
  int a, b, t; cin >> a >> b >> t;
  int ans = 0;
  for(int i = 0; i < (t / a); i++){
    ans += b;
  }
  cout << ans << endl;
}