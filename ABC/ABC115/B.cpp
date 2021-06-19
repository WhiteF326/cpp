#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(i, j) make_pair(i, j);
using ll = long long;
using ld = long double;

int main(){
  int n; cin >> n;
  vector<int> p(n);
  for(int i = 0; i < n; i++) cin >> p[i];
  sort(p.begin(), p.end());
  cout << accumulate(p.begin(), p.end(), 0) - p[n - 1] / 2 << endl;
}