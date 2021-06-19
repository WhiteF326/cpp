#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j)
using ll = long long;
using ld = long double;

int main(){
  ll s, p; cin >> s >> p;
  for(ll i = 1; i <= ceil(sqrt(p)); i++){
    if(p % i) continue;
    if(s == i + (p / i)){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}