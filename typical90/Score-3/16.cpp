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
  int ans = INT_MAX;
  int a, b, c; cin >> a >> b >> c;
  for(int i = 0; i <= 9999; i++){
    if(n < i * a) break;
    for(int j = 0; j <= 9999 - i; j++){
      if(n < i * a + j * b) break;
      if((n - i * a - j * b) % c == 0){
        int k = (n - i * a - j * b) / c;
        ans = min(ans, i + j + k);
      }
    }
  }
  cout << ans << endl;
}