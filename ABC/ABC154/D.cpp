#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, k; cin >> n >> k;
  vector<double> p(n);
  for(int i = 0; i < n; i++){
    double t; cin >> t;
    p[i] = (1.0 + t) / 2.0;
  }
  double s = 0.0; double ans = 0.0;
  for(int i = 0; i < k; i++){s += p[i];}
  ans = s;
  for(int i = 0; i < n - k; i++){
    s += p[i + k] - p[i];
    ans = max(s, ans);
  }
  cout << fixed << setprecision(12) << ans << endl;
}