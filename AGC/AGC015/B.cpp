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
  int n = s.length();

  ll ans = 0;
  for(int i = 0; i < n; i++){
    if(s[i] == 'U'){
      ans += (n - i - 1);
      ans += i * 2;
    }else{
      ans += (n - i - 1) * 2;
      ans += i;
    }
  }
  cout << ans << endl;
}