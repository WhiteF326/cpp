#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
using ll = long long;
using ld = long double;

int main(){
  ll n; cin >> n;
  if(n == 2){
    cout << 0 << endl;
    return 0;
  }
  ll dn = n;
  // 素因数分解
  queue<int> t;
  bool c = true;
  while(c){
    c = false;
    for(int i = 2; i <= ceil(sqrt(n)); i++){
      if(n % i == 0){
        n /= i;
        t.push(i);
        c = true;
        break;
      }
    }
  }
  if(n == dn) cout << 0 << endl;
  else{
    if(n != 1) t.push(n);
    cout << ceil(log2(t.size())) << endl;
  }
}