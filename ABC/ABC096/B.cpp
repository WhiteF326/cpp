#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  vector<int> v(3); cin >> v[0] >> v[1] >> v[2];
  int k; cin >> k;
  sort(v.begin(), v.end());
  cout << v[0] + v[1] + v[2] * pow(2, k) << endl;
}