#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(i, j) make_pair(i, j);
using ll = long long;
using ld = long double;

int main(){
  vector<int> v(3);
  for(int i = 0; i < 3; i++) cin >> v[i];
  sort(v.begin(), v.end());
  cout << v[0] + v[1] + v[2] * 10 << endl;
}