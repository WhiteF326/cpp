#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;

int main(){
  int x; cin >> x;
  if(x >= 90){
    cout << "expert" << endl;
  }else if(x >= 70){
    cout << 90 - x << endl;
  }else if(x >= 40){
    cout << 70 - x << endl;
  }else{
    cout << 40 - x << endl;
  }
}