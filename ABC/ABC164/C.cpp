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
  map<string, int> s;
  for(int i = 0; i < n; i++){
    string c; cin >> c;
    s[c]++;
  }
  cout << s.size() << endl;
}