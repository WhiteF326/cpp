#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, p;
  cin >> n >> p;
  int m = 0;
  for(int i = 0; i < n; i++){
    int a; cin >> a;
    if(a % 2) m++;
  }
  if(m) cout << (1LL << (n - 1)) << endl;
  else cout << (p == 0 ? (1LL << n) : 0) << endl;
}