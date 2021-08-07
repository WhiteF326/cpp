#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
using ll = long long;
using ld = long double;

int main(){
  int n; cin >> n;
  string t; cin >> t;
  ll v = 10000000000LL;
  string x = "110";

  if(t == "1") cout << 2 * v << endl;
  else if(t == "0" || t == "11") cout << v << endl;
  else{
    ll res = 0;
    for(int i = 0; i < 3; i++){
      ll a = (t.size() + i + 2) / 3;

      bool flg = true;
      for(int j = 0; j < t.size(); j++){
        if(t[j] != x[(j + 1) % 3]) flg = false;
      }
      if(flg) res += v - a + 1;
    }
    cout << res << endl;
  }
  
}