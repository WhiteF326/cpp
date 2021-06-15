#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  int a, b; cin >> a >> b;
  string as, bs;
  for(int i = 0; i < b; i++){
    as += to_string(a);
  }
  for(int i = 0; i < a; i++){
    bs += to_string(b);
  }
  cout << min(as, bs) << endl;
}