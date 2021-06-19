#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(i, j) make_pair(i, j);
using ll = long long;
using ld = long double;

int main(){
  int n; cin >> n;
  for(int i = 1; i <= 9; i++){
    if(n <= i * 111){
      cout << i * 111 << endl;
      return 0;
    }
  }
}