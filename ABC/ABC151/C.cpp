#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j)
using ll = long long;
using ld = long double;

int main(){
  int n, m; cin >> n >> m;
  map<int, int> rest;
  vector<bool> q(n, true);
  int ans = 0, res = 0;
  for(int i = 0; i < m; i++){
    int p; string s; cin >> p >> s;
    if(s == "WA" && q[p]){
      rest[p]++;
    }else{
      ans += rest[p];
      rest[p] = 0;
      res += q[p];
      q[p] = false;
    }
  }
  cout << res << " " << ans << endl;
}