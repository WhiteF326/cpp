#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  ll x; cin >> x;
  ll d = 100;
  for(int i = 0; i < 10000000; i++){
    d = d / 100 + d;
    if(d >= x){
      cout << i + 1 << endl;
      return 0;
    }
  }
}