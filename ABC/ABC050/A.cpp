#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  int a, b; string op; cin >> a >> op >> b;
  if(op == "+") cout << a + b << endl;
  else cout << a - b << endl;
}