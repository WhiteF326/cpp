// this problem sucks I'll never do this again

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j);
using ll = long long;
using ld = long double;

const ll modv = 1000000007;

int main(){
  int h1, m1, h2, m2; cin >> h1 >> m1 >> h2 >> m2;
  int x = h2 * 60 + m2 - (h1 * 60 + m1);
  int k; cin >> k;
  cout << x - k << endl;
}
