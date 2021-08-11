#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  int n; cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];

  vector<int> spl(1000001, 0);
  spl[1] = 1;
  for(int i = 2; i <= 1000000; i++){
    if(spl[i]) continue;
    for(int j = i; j <= 1000000; j += i){
      spl[j] = i;
    }
  }

  vector<int> grundy(n);
  for(int i = 0; i < n; i++){
    while(a[i] > 1){
      a[i] /= spl[a[i]];
      grundy[i]++;
    }
  }
  
  // all xor
  int nimber = 0;
  for(int i = 0; i < n; i++){
    nimber = nimber ^ grundy[i];
  }
  cout << (nimber ? "white" : "black") << endl;
}