#include <bits/stdc++.h>
using namespace std;

#define fs(n) fixed << setprecision(n);
using ll = long long;

int main(){
  int a, b, c; cin >> a >> b >> c;
  cout << a + b + c - min(a, min(b, c)) << endl;
}