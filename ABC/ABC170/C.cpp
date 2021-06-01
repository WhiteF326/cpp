#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j);
using ll = long long;
using ld = long double;

int main(){
  int x, n; cin >> x >> n;
  vector<bool> a(102, true);
  for(int i = 0; i < n; i++){
    int p; cin >> p;
    a[p] = false;
  }
  int ans = 0, mn = INT_MAX;
  for(int i = 0; i < 102; i++){
    if(a[i]){
      if(abs(x - i) < mn){
        mn = abs(x - i);
        ans = i;
      }
    }
  }
  cout << ans << endl;
}