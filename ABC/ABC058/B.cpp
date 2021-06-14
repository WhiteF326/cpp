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
  string o, e; cin >> o >> e; string ans = "";
  for(int i = 0; i < (int)min(o.length(), e.length()); i++){
    ans += o.substr(i, 1) + e.substr(i, 1);
  }
  if(o.length() > e.length()){ans += o.substr(o.length() - 1, 1);}
  cout << ans << endl;
}