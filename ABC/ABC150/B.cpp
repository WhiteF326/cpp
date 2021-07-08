#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  int n; cin >> n;
  string s; cin >> s;

  int ans = 0;
  for(int i = 0; i < n - 2; i++){
    if(s.substr(i, 3) == "ABC"){
      ans++;
    }
  }
  cout << ans << endl;
}