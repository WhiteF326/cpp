#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j);
using ll = long long;
using ld = long double;

int main(){
  ll n; cin >> n;
  ll ans = 0;
  for(int i = (int)sqrt(n); i >= 1; i--){
    if(n % i == 0){
      ans = (n / i) + i - 2;
      break;
    }
  }
  cout << (ans ? ans : n - 1) << endl;
}