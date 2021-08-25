#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  string s; cin >> s;
  int ans = 0;
  for(int i = 0; i < 4; i++){
    if(s[i] == '2') ans++;
  }
  cout << ans << endl;
}