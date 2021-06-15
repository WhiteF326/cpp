#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  int k, x; cin >> k >> x;
  for(int i = x - k + 1; i < x + k - 1; i++){
    cout << i << " ";
  }cout << x + k - 1 << endl;
}