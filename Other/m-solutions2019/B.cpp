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
  int ocnt = 0;
  for(int i = 0; i < s.length(); i++){
    if(s.substr(i, 1) == "o") ocnt++;
  }
  int lastd = 15 - s.length();
  ocnt = 8 - ocnt;
  if(ocnt <= lastd) cout << "YES" << endl;
  else cout << "NO" << endl;
}