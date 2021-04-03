#include <bits/stdc++.h>
using namespace std;

int fact(int x) {return x <= 1 ? 1 : x * fact(x - 1);}

int main(){
  int n; cin >> n;
  if(n == 3 || n == 5 || n == 7) cout << "YES";
  else cout << "NO";
  cout << endl;
}