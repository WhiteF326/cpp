#include <bits/stdc++.h>
using namespace std;

#define fs(n) fixed << setprecision(n);
using ll = long long;

int main(){
  int n; cin >> n;
  ll ans = 0;
  for(ll i = 1; i <= 160000; i++){
    ans += i;
    if(ans >= n){
      cout << i << endl;
      return 0;
    }
  }
}