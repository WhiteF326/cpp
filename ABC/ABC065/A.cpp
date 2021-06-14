#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j);
using ll = long long;
using ld = long double;

const ll modv = 1000000007;

int main(){
  int x, a, b; cin >> x >> a >> b;
  if(a >= b){
    cout << "delicious" << endl;
  }else if(x >= b - a){
    cout << "safe" << endl;
  }else{
    cout << "dangerous" << endl;
  }
}