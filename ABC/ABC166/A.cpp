#include <bits/stdc++.h>
using namespace std;

int fact(int x) {return x <= 1 ? 1 : x * fact(x - 1);}

int main(){
  string s; cin >> s;
  cout << (s == "ABC" ? "ARC" : "ABC") << endl;
}