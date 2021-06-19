#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(i, j) make_pair(i, j);
using ll = long long;
using ld = long double;

int main(){
  ll a, b, c, d; cin >> a >> b >> c >> d;
  if(max(a, c) <= min(b, d)){
    cout << "Yes" << endl;
  }else cout << "No" << endl;
}