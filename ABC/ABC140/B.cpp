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
  vector<int> a(n), b(n), c(n - 1);
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < n; i++) cin >> b[i];
  for(int i = 0; i < n - 1; i++) cin >> c[i];
  int ans = 0;
  for(int i = 0; i < n; i++){
    ans += b[a[i] - 1];
    if(i > 0){
      if(a[i] - 1 == a[i - 1]) ans += c[a[i - 1] - 1];
    }
  }
  cout << ans << endl;
}