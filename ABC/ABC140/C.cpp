#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;
  vector<int> b(n - 1);
  for (int i = 0; i < n - 1; ++i) cin >> b[i];

  int ans = b[0] + b.back();
  for (int i = 0; i + 1 < b.size(); ++i) {
    ans += min(b[i], b[i + 1]);
  }
  cout << ans << endl;
}