#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

ll modv = 1000000007;

int main(){
  int n; cin >> n;
  vector<string> s(2);
  cin >> s[0] >> s[1];

  ll ans = 1;
  string before = "n";
  for(int i = 0; i < n; i++){
    if(s[0][i] == s[1][i]){
      // vertical
      if(before == "n"){
        ans *= 3;
      }else if(before == "v"){
        ans *= 2;
      }
      before = "v";
    }else{
      // horizontal
      if(before == "n"){
        ans *= 6;
      }else if(before == "v"){
        ans *= 2;
      }else{
        ans *= 3;
      }
      before = "h";
      i++;
    }
    ans %= modv;
  }
  cout << ans << endl;
}