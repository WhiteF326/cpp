#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j)
using ll = long long;
using ld = long double;

int main(){
  int n, x; cin >> n >> x;
  cout << min(x - 1, n - x) << endl;
}