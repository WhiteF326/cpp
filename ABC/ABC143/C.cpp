#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j);
using ll = long long;
using ld = long double;

int main(){
  int n; cin >> n;
  string s; cin >> s;
  string t = s.substr(0, 1);
  for(int i = 1; i < n; i++){
    if(s.substr(i, 1) != s.substr(i - 1, 1)){
      t += s.substr(i, 1);
    }
  }
  cout << t.length() << endl;
}