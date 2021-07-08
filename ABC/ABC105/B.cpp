#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  int n; cin >> n;

  for(int k = 0; k < 100; k++){
    for(int d = 0; d < 100; d++){
      if(k * 4 + d * 7 == n){
        cout << "Yes" << endl;
        return 0;
      }
    }
  }

  cout << "No" << endl;
}