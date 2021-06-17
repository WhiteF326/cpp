#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  int a, b; cin >> a >> b;
  if(a + b == 15) cout << "+" << endl;
  else if(a * b == 15) cout << "*" << endl;
  else cout << "x" << endl;
}