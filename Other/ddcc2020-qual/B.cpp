#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; long long c = 0, sum = 0; cin >> n; vector<int> a(n);
  for(int i = 0; i < n; i++){cin >> a[i]; sum += a[i];}
  long long res = 1LL<<60;
  for(int i = 0; i < n; i++){
    c += a[i]; sum -= a[i];
    res = min(res, abs(c - sum));
  }
  cout << res << endl;
}