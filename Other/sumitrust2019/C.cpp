#include <bits/stdc++.h>
using namespace std;

int main(){
  int x; cin >> x;
  cout << ((x % 100) <= 5 * (x / 100)) << endl;
}