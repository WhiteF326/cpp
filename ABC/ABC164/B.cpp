#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  while(true){
    c -= b;
    if(c <= 0){
      cout << "Yes" << endl;
      break;
    }
    a -= d;
    if(a <= 0){
      cout << "No" << endl;
      break;
    }
  }
}