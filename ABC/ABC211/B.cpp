#include <bits/stdc++.h>
using namespace std;

#define fs(n) fixed << setprecision(n);
using ll = long long;

int main(){
  vector<string> s(4);
  for(int i = 0; i < 4; i++) cin >> s[i];
  sort(s.begin(), s.end());
  vector<string> ans = {"2B", "3B", "H", "HR"};
  if(s == ans) cout << "Yes" << endl;
  else cout << "No" << endl;
}