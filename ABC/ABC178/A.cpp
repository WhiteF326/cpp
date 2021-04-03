#include <bits/stdc++.h>
using namespace std;

int fact(int x) {return x <= 1 ? 1 : x * fact(x - 1);}

int main(){
  int n; cin >> n;
  cout << (int)!(bool)n << endl;
}