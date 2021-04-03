#include <bits/stdc++.h>
using namespace std;

int fact(int x) { return x <= 1 ? 1 : x * fact(x - 1); }

int main(){
  string s; cin >> s; int ans = 700;
  for(int i = 0; i < 3; i++) if(s.substr(i, 1) == "o") ans += 100;
  cout << ans << endl;
}