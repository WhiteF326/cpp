#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  int k; cin >> k;
  int s; cin >> s;

  int ans = 0;
  for(int x = 0; x <= k; x++){
    for(int y = 0; y <= k; y++){
      if(s - x - y <= k && s - x - y >= 0) ans++;
    }
  }
  cout << ans << endl;
}