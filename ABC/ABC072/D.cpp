#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  int n; cin >> n;
  vector<int> toswap(n, false);
  for(int i = 0; i < n; i++){
    int p; cin >> p;
    if(p == i + 1) toswap[i] = true;
  }
  int i = 0, ans = 0;
  while(i < n){
    if(toswap[i]){
      ans++;
      if(toswap[i + 1]) i++;
    }
    
    i++;
  }
  cout << ans << endl;
}