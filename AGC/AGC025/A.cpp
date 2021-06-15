#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  int n; cin >> n;
  // aを決めるとbは一意、aとbをswapしても同じ
  int ans = INT_MAX;
  for(int i = 1; i <= (n / 2 + n % 2); i++){
    int a = i, b = n - i;
    int res = 0;
    for(int j = 0; j < log10(a + 1); j++){
      res += (int)(a / (int)pow(10, j)) % 10;
    }
    for(int j = 0; j < log10(b + 1); j++){
      res += (int)(b / (int)pow(10, j)) % 10;
    }
    ans = min(ans, res);
  }
  cout << ans << endl;
}