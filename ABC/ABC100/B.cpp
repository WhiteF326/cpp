#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, d; cin >> n >> d;
  if(d == 100) d++;
  cout << fixed << (int)(pow(100, n) * d) << endl;
}