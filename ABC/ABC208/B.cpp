#include <bits/stdc++.h>
using namespace std;

#define fs(n) fixed << setprecision(n);
using ll = long long;

int main(){
  int p; cin >> p;
  vector<int> factlist = {
    1,
    1,
    2,
    6,
    24,
    120,
    720,
    5040,
    40320,
    362880,
    3628800
  };
  int ans = 0;
  for(int i = 10; i >= 1; i--){
    ans += p / factlist[i];
    p = p % factlist[i];
  }
  cout << ans << endl;
}