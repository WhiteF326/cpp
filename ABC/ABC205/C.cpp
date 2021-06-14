#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
using ll = long long;
using ld = long double;

int main(){
  int a, b, c; cin >> a >> b >> c;
  if(c % 2){
    // odd
    if(a == b) cout << "=" << endl;
    else if(a < b) cout << "<" << endl;
    else cout << ">" << endl;
  }else{
    // even
    a = abs(a), b = abs(b);
    if(a == b) cout << "=" << endl;
    else if(a < b) cout << "<" << endl;
    else cout << ">" << endl;
  }
}