#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(i, j) make_pair(i, j);
using ll = long long;
using ld = long double;

int main(){
  int a, b, c; cin >> a >> b >> c;
  map<int, int> st;
  st[1] = a, st[0] = b, st[-1] = c;
  int k; cin >> k;
  int ans = 0;

  for(int i = 1; i >= -1; i--){
    ans += i * min(k, st[i]);
    k -= st[i];
    if(k <= 0) break;
  }
  cout << ans << endl;
}