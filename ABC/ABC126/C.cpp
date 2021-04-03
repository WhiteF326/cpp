#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, k; cin >> n >> k;
  double ans = 0.0;
  for(int i = 1; i <= n; i++){
    int t = i; double ta = 10000.0 / (double)n;
    while(t < k){
      t = t * 2; ta = ta / 2.0;
    }
    ans += (ta / 10000.0);
  }
  cout << fixed << setprecision(12) << ans << endl;
}