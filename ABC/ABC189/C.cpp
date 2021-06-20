#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
using ll = long long;
using ld = long double;

int main(){
  int n; cin >> n;
  // 尺取り出来る？
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  
  int ans = 0;
  for(int l = 0; l < n; l++){
    int areamin = a[l];
    for(int r = l; r < n; r++){
      areamin = min(areamin, a[r]);
      ans = max(ans, areamin * (r - l + 1));
    }
  }
  cout << ans << endl;
}