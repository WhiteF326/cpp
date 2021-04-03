#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n; vector<int> a(n), b(n, 0);
  for(int i = 0; i < n; i++){cin >> a[i];}
  for(int i = 1; i < n; i++){
    if(a[i] <= a[i - 1]){b[i] = b[i - 1] + 1;}
    else{b[i] = 0;}
  }
  int ans = 0;
  for(int i = 0; i < n; i++){ans = max(ans, b[i]);}
  cout << ans << endl;
}