#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j);
using ll = long long;
using ld = long double;

int gcd(int i, int j){
  if(i % j){
    return gcd(j, i % j);
  }else return j;
}

int main(){
  int k; cin >> k;
  int ans = 0;
  for(int a = 1; a <= k; a++){
    for(int b = 1; b <= k; b++){
      int t = gcd(a, b);
      for(int c = 1; c <= k; c++){
        ans += gcd(t, c);
      }
    }
  }
  cout << ans << endl;
}