#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  int n, m; cin >> n >> m;
  vector<int> a(n);
  for(int i = 0; i < m; i++) cin >> a[i];

  cout << max(-1, n - accumulate(a.begin(), a.end(), 0)) << endl;
}