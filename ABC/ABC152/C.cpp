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
  int n; cin >> n;
  int ans = 1;
  int p; cin >> p;
  for(int i = 1; i < n; i++){
    int x; cin >> x;
    if(p > x){
      ans++;
      p = x;
    }
  }
  cout << ans << endl;
}