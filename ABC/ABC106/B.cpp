#include <bits/stdc++.h>
using namespace std;

int fact(int x) { return x <= 1 ? 1 : x * fact(x - 1); }

int main(){
  int n; cin >> n;
  int ans = 0;
  for(int i = 1; i <= n; i += 2){
    int dcnt = 0;
    for(int j = 1; j <= (int)floor(sqrt(i)); j++){
      if((i % j) == 0)dcnt += 2;
    }
    if(dcnt == 8){ans++;}
  }
  cout << ans << endl;
}