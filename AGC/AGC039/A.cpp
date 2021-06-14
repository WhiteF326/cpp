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
  string s; cin >> s;
  ll k; cin >> k;
  string t = s.substr(0, 1);
  vector<ll> cons(0);
  int v = 1;
  for(int i = 1; i < s.length(); i++){
    if(t == s.substr(i, 1)){
      v++;
    }else{
      cons.emplace_back(v);
      t = s.substr(i, 1);
      v = 1;
    }
  }
  cons.emplace_back(v);
  if(cons.size() == 1){
    cout << (s.length() * k) / 2 << endl;
    return 0;
  }
  ll a = cons[0], b = cons[cons.size() - 1];
  ll ans = 0;
  for(int i = 0; i < cons.size(); i++){
    cons[i] /= 2;
    ans += cons[i];
    // cout << cons[i];
  }
  ans *= k;
  if(s.substr(0, 1) != s.substr(s.length() -1, 1)){
    cout << ans << endl;
  }else{
    cout << ans - (k - 1) * (a / 2 + b / 2 - ((a + b) / 2)) << endl;
  }
}