#include <bits/stdc++.h>
using namespace std;

int fact(int x) { return x <= 1 ? 1 : x * fact(x - 1); }

int main(){
  int a, b, c, d; cin >> a >> b >> c >> d;
  if(a + b > c + d) cout << "Left";
  else if(a + b < c + d) cout << "Right";
  else cout << "Balanced";
  cout << endl;
}