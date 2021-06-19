#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j)
using ll = long long;
using ld = long double;

int main(){
  int a, b, c; cin >> a >> b >> c;
  int k; cin >> k;

  for(int i = 0; i < k; i++){
    if(a < b) c *= 2;
    else b *= 2;
  }

  cout << ((a < b && b < c) ? "Yes" : "No") << endl;
}