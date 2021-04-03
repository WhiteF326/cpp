#include <bits/stdc++.h>
using namespace std;

int main(){
  long long a, b, c, k; cin >> a >> b >> c >> k;
  long long na, nb, nc;
  na = a + (a + b + c) * (k / 2);
  nb = b + (a + b + c) * (k / 2);
  nc = c + (a + b + c) * (k / 2);
  a = na; b = nb; c = nc;
  if(k % 2 == 1){
    na = b + c; nb = a + c; nc = a + b;
    a = na; b = nb; c = nc;
  }
  if(abs(a - b) > pow(10, 18)){cout << "Unfair" << endl;}
  else{cout << a - b << endl;}
}