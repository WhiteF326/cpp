#include <bits/stdc++.h>
using namespace std;

#define ld long double

int main(){
  ld n, m; cin >> n >> m;

  ld d = 1, c = 0;
  while(n / d > m){
    d *= 3;
    c++;
  }

  cout << c << endl;
}
