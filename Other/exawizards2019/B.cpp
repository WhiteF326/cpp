#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  int n; cin >> n;
  string s; cin >> s;

  map<string, int> x;
  for(int i = 0; i < n; i++) x[s.substr(i, 1)]++;

  if(x["R"] > x["B"]) cout << "Yes" << endl;
  else cout << "No" << endl;
}