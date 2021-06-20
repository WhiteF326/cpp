#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  int a, b, k; cin >> a >> b >> k;
  vector<int> v = {a, b};

  for(int i = 0; i < k; i++){
    v[i % 2] -= v[i % 2] % 2;
    v[(i + 1) % 2] += v[i % 2] / 2;
    v[i % 2] /= 2;
  }
  cout << v[0] << " " << v[1] << endl;
}