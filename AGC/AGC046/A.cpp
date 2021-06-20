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
  int x; cin >> x;
  for(int i = 1; i <= 360; i++){
    if((x * i) % 360 == 0){
      cout << i << endl;
      return 0;
    }
  }
}
