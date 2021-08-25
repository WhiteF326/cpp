#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  int n; cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];

  vector<int> grundy(n, 0);
  for(int i = 0; i < n; i++){
    int p = a[i];
    for(int j = 2; j <= ceil(sqrt(a[i])); j++){
      while(p % j == 0){
        p /= j;
        grundy[i]++;
      }
    }
  }
  
  // all xor
  int nimber = 0;
  for(int i = 0; i < n; i++){
    nimber = nimber ^ grundy[i];
  }
  cout << (nimber ? "white" : "black") << endl;
}