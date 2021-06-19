#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j)
using ll = long long;
using ld = long double;

int main(){
  int a, b, c; cin >> a >> b >> c;
  cout << a * b * 2 + b * c * 2 + a * c * 2 << endl;
}