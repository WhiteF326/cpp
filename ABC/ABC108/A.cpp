#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  int k; cin >> k;
  int even = 0, odd = 0;
  for(int i = 1; i <= k; i++){
    if(i % 2) odd++;
    else even++;
  }
  cout << odd * even << endl;
}