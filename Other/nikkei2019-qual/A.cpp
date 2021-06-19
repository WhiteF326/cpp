#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(i, j) make_pair(i, j);
using ll = long long;
using ld = long double;

int main(){
  int n, a, b; cin >> n >> a >> b;
  cout << min(a, b) << " " << max(0, a + b - n) << endl;
}