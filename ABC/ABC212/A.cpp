#include <bits/stdc++.h>
using namespace std;

#define fs(n) fixed << setprecision(n)
using ll = long long;

int main(){
  int a, b; cin >> a >> b;
  if(a == 0) cout << "Silver" << endl;
  else if(b == 0) cout << "Gold" << endl;
  else cout << "Alloy" << endl;
}