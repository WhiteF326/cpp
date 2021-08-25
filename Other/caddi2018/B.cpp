#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(i, j) make_pair(i, j);
using ll = long long;
using ld = long double;

int main(){
  int n; cin >> n;
  int h, w; cin >> h >> w;
  int ans = 0;
  for(int i = 0; i < n; i++){
    int a, b; cin >> a >> b;
    ans += (a >= h) && (b >= w);
  }
  cout << ans << endl;
}