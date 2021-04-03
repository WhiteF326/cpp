#include <bits/stdc++.h>
using namespace std;

int main(){
  int f; cin >> f;
  long ans = 0;
  for(int i = 1; i <= f; i++){
    if(i % 3 && i % 5){ans += i;}
  }
  cout << ans << endl;
}