#include <bits/stdc++.h>
using namespace std;

#define fs(n) fixed << setprecision(n)
using ll = long long;

int main(){
  double a, b; cin >> a >> b;
  cout << fs(12) << (a - b) / 3.0 + b << endl;
}