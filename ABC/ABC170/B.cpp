#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j)
using ll = long long;
using ld = long double;

int main(){
  int x, y; cin >> x >> y;
  int t = x, k = 0;
  while(t >= 0){
    if(t * 2 + k * 4 == y){
      cout << "Yes" << endl;
      return 0;
    }
    t--, k++;
  }
  cout << "No" << endl;
}