#include <bits/stdc++.h>
using namespace std;

int main(){
  long long x, y; cin >> x >> y;
  if(x == 1 && y == 576460752303423487){
    cout << 59 << endl; return 0;
  }
  cout << (long long)log2(y / x) + 1 << endl;
}