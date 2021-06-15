#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  int n; cin >> n;
  int odd = 0;
  for(int i = 1; i <= n; i++){
    if(i % 2) odd++;
  }
  cout << fixed << setprecision(12) << ((double)odd / (double)n) << endl;
}