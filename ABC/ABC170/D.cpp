#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  int n; cin >> n;

  // 10^6までなので約数列挙できる
  vector<int> a(n);
  map<int, int> app;
  for(int i = 0; i < n; i++){
    cin >> a[i];
    app[a[i]]++;
  }

  vector<bool> x(1000001, false);
  for(int i = 0; i < n; i++) x[a[i]] = true;
  int ans = 0;

  sort(a.begin(), a.end());
  for(int i = 0; i < n; i++){
    if(app[a[i]] >= 2) continue;
    bool flg = true;
    for(int j = 2; j <= (int)sqrt(a[i]); j++){
      if(a[i] % j == 0){
        if(x[j] || x[a[i] / j]){
          flg = false;
        }
      }
    }
    ans += flg;
  }
  cout << ans << endl;
}