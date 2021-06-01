#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j);
using ll = long long;
using ld = long double;

int main(){
  int n; cin >> n;
  int ans = 0;
  const double l8 = log(8);
  for(int i = 1; i <= n; i++){
    bool flg = true;
    // decimal
    for(int j = 0; j < log10(i + 1); j++){
      if((int)(i / pow(10, j)) % 10 == 7){
        flg = false;
      }
    }
    // octal
    for(int j = 0; j < (log(i + 1) / l8); j++){
      if((int)(i / pow(8, j)) % 8 == 7){
        flg = false;
      }
    }
    ans += flg;
  }
  cout << ans << endl;
}