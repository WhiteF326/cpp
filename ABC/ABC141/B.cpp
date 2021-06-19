#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(i, j) make_pair(i, j);
using ll = long long;
using ld = long double;

int main(){
  string s; cin >> s;
  bool ans = true;
  for(int i = 0; i < s.length(); i++){
    if((s[i] == 'R' && i % 2) || (s[i] == 'L' && i % 2 == 0)) ans = false;
  }
  cout << (ans ? "Yes" : "No") << endl;
}