#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;

int main(){
  ll n; cin >> n;
  string m = to_string(n);
  int s = m.size();

  ll ans = 0;
  for(ll i = 0; i < (1LL << s); i++){
    string l = "", r = "";
    for(int j = 0; j < s; j++){
      if(i & (1LL << j)){
        l.push_back(m[j]);
      }else{
        r.push_back(m[j]);
      }
    }
    if(l == "" || r == "") continue;
    sort(all(l), greater<char>());
    sort(all(r), greater<char>());
    ll ls = stoll(l);
    ll rs = stoll(r);
    if(!ls || !rs) continue;

    ans = max(ans, ls * rs);
  }
  cout << ans << endl;
}