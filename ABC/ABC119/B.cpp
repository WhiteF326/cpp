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
  ld ans = 0.0;
  for(int i = 0; i < n; i++){
    string s, t; cin >> s >> t;
    if(t == "JPY"){
      ans += stoi(s);
    }else{
      ll b = stoll(s.substr(0, s.length() - 9)) * 100000000;
      b += stoll(s.substr(s.length() - 8));
      ans += 380000.0 * b / 100000000.0;
    }
  }
  cout << fs(12) << ans << endl;
}