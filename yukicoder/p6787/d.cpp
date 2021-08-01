#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  ofstream ofs("o.txt");
  ll x = 1;
  for(int i = 1; i <= 19; i++){
    ofs << x << endl;
    x *= i;
  }
}