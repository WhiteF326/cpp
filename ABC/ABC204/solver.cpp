#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  int c, d, t; cin >> c >> d >> t;
  int ans = INT_MAX;
  for(int i = 0; i < 100000; i++){
    ans = min(ans, c + i + (int)(d / (double)(t + i + 1)));
    
  }
  cout << ans << endl;
}