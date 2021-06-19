#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j)
using ll = long long;
using ld = long double;

int main(){
  int n; cin >> n;
  int h; cin >> h;
  int ans = 1;
  for(int i = 0; i < n - 1; i++){
    int v; cin >> v;
    if(v >= h){
      ans++;
      h = v;
    }
  }
  cout << ans << endl;
}