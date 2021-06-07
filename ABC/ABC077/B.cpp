#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j)
using ll = long long;
using ld = long double;

int main(){
  int n; cin >> n;
  for(int i = 1; i <= 100000; i++){
    if(pow(i, 2) > n){
      cout << fs(0) << (int)pow(i - 1, 2) << endl;
      break;
    }
  }
}