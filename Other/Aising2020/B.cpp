#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  int n; cin >> n;
  int ans = 0;
  for(int i = 0; i < n; i++){
    int a; cin >> a;
    if((i + 1) % 2 && a % 2) ans++;
  }
  cout << ans << endl;
}