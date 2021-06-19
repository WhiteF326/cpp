#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j)
using ll = long long;
using ld = long double;

int main(){
  int x, y, z; cin >> x >> y >> z;
  int h = y + z;
  x -= z;
  cout << x / h << endl;
}