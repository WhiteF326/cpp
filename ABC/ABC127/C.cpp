#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int n, m; cin >> n >> m;
  int s = 0, u = n + 1;
  for(int i = 0; i < m; i++){
    int l, r; cin >> l >> r;
    s = max(s, l); u = min(u, r);
  }
  if(s > u){cout << 0 << endl;}else{cout << u - s + 1 << endl;}
}