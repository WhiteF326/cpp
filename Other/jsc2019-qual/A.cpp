#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j)
using ll = long long;
using ld = long double;

int main(){
  int m; int d; cin >> m >> d;
  int ans = 0;
  for(int i = 4; i <= m; i++){
    for(int j = 22; j <= d; j++){
      int d1 = j % 10;
      if(d1 >= 2 && (floor(j / 10) * d1 == i)) ans++;
    }
  }
  cout << ans << endl;
}