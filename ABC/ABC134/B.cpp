#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(i, j) make_pair(i, j);
using ll = long long;
using ld = long double;

int main(){
  int n, d; cin >> n >> d;
  d = d * 2 + 1;
  cout << ceil(n / (double)d) << endl;
}