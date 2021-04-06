#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;
  int order = ((n - 1) / 20) % 2;
  int ans = 0;
  if(order){
    ans = 21 - (n % 20);
    if(ans == 21) ans = 1;
  }else{
    ans = n % 20;
    if(ans == 0) ans = 20;
  }
  cout << ans << endl;
}