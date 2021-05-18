#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  int n, m; cin >> n >> m;
  int d = n - m;
  double ans = 1900 * m + 100 * (n - m);
  ans *= (int)pow(2, m);
  cout << ans << endl;
}