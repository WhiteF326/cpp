#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j)
using ll = long long;
using ld = long double;

int main(){
  int t; cin >> t;
  for(int i = 0; i < t; i++){
    ll n; cin >> n;
    if(n % 4 == 0) cout << "Even" << endl;
    else if(n % 2 == 0) cout << "Same" << endl;
    else cout << "Odd" << endl;
  }
}