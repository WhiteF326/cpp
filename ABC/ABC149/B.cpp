#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j);
using ll = long long;
using ld = long double;

int main(){
  ll a, b, k; cin >> a >> b >> k;

  if(k > a){
    k -= a;
    a = 0;
    b -= k;
    cout << a << " " << (b < 0 ? 0 : b) << endl;
  }else{
    cout << (a - k) << " " << b << endl;
  }
}