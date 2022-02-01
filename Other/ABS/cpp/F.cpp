#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, a, b;
  cin >> n >> a >> b;
  int ans = 0;
  for(int i = 1; i <= n; i++){
    int q = 0;
    for(int j = 0; j < to_string(i).size(); j++){
      q += (i / (int)pow(10.0, (double)j)) % 10;
    }
    if(a <= q && q <= b){
      ans += i;
    }
  }
  cout << ans << endl;
  return 0;
}