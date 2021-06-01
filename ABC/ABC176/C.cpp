#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j);
using ll = long long;
using ld = long double;

int main(){
  int n; cin >> n;
  int d; cin >> d;
  ll ans = 0;
  for(int i = 1; i < n; i++){
    int x; cin >> x;
    if(x < d){
      ans += (d - x);
    }else if(x > d){
      d = x;
    }
  }
  cout << ans << endl;
}