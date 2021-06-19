#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(i, j) make_pair(i, j);
using ll = long long;
using ld = long double;

int main(){
  string a, b; cin >> a >> b;
  bool al = a == "H", bl = b == "H";
  cout << (!(al ^ bl) ? "H" : "D") << endl;
}