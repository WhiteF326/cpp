#include <bits/stdc++.h>
using namespace std;

int main(){
  long long n; cin >> n;
  long long ans = 0;
  for(int i = (int)sqrt(n); i >= 1; i--){
    if(n % i == 0){
      ans = (n / i) + i - 2;
      break;
    }
  }
  cout << (ans ? ans : n - 1) << endl;
}