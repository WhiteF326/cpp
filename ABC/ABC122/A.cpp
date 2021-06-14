#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j);
using ll = long long;
using ld = long double;

const ll modv = 1000000007;

int main(){
  string b; cin >> b;
  map<string, string> ans;
  ans["A"] = "T";
  ans["C"] = "G";
  ans["G"] = "C";
  ans["T"] = "A";
  cout << ans[b] << endl;
}