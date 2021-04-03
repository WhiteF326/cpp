#include <bits/stdc++.h>
using namespace std;

int fact(int x) { return x <= 1 ? 1 : x * fact(x - 1); }

int main(){
  vector<int> s(3); for(int i = 0; i < 3; i++) cin >> s[i];
  sort(s.begin(), s.end());
  cout << s[2] - s[0] << endl;
}