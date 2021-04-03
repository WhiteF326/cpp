#include <bits/stdc++.h>
using namespace std;

int fact(int x) {return x <= 1 ? 1 : x * fact(x - 1);}

int main(){
  int a, b; cin >> a >> b;
  cout << (2 * a + 100) - b << endl;
}