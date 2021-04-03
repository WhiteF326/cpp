#include <bits/stdc++.h>
using namespace std;

int fact(int x) {return x <= 1 ? 1 : x * fact(x - 1);}

int main(){
  string s; cin >> s;
  cout << s.substr(0, 5) + " " + s.substr(6, 7) + " " + s.substr(14, 5) << endl;
}