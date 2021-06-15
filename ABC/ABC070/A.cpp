#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  string n; cin >> n;
  string t = n;
  reverse(t.begin(), t.end());
  if(n == t) cout << "Yes" << endl;
  else cout << "No" << endl;
}