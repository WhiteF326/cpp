#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  int a, b, c; cin >> a >> b >> c;
  int res = a * 100 + b * 10 + c;
  if(res % 4) cout << "NO" << endl;
  else cout << "YES" << endl;
}