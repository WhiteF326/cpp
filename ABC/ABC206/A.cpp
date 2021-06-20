#include <bits/stdc++.h>
using namespace std;

#define fs(n) fixed << setprecision(n);
using ll = long long;

int main(){
  int n; cin >> n;
  n = n * 108 / 100;
  if(n == 206) cout << "so-so" << endl;
  else if(n < 206) cout << "Yay!" << endl;
  else cout << ":(" << endl;
}