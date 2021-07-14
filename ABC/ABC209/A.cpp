#include <bits/stdc++.h>
using namespace std;

#define fs(n) fixed << setprecision(n);
using ll = long long;

int main(){
  int a, b; cin >> a >> b;
  int ans = 0;
  for(int i = 0; i <= 100; i++){
    if(i >= a && i <= b) ans++;
  }
  cout << ans << endl;
}