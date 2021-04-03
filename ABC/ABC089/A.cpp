#include <bits/stdc++.h>
using namespace std;

int fact(int x) { return x <= 1 ? 1 : x * fact(x - 1); }

int main(){
  int a; cin >> a;
  cout << (int)floor(a / 3) << endl;
}