#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, a, b; cin >> n >> a >> b;
  int ans = 0;
  for(int i = 1; i <= n; i++){
    int ss = 0;
    for(int j = 0; j < (int)ceil(log10(i + 1)); j++){
      ss += (i / (int)pow(10, j)) % 10;
    }
    if(a <= ss && ss <= b){ans += i;}
  }
  cout << ans << endl;
}