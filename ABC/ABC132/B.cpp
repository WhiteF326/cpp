#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j);
using ll = long long;
using ld = long double;

const ll modv = 1000000007;

int main(){
  int n; cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];

  int ans = 0;
  for(int i = 1; i < n - 1; i++){
    if(a[i - 1] < a[i] && a[i] < a[i + 1]) ans++;
    else if(a[i - 1] > a[i] && a[i] > a[i + 1]) ans++;
  }
  cout << ans << endl;
}
