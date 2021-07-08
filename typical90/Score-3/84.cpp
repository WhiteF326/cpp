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
  
  int b = 0, e = 0;
  char o = 'o', x = 'x';
  map<char, int> ap;
  ap[s[0]]++;
  ll ans = 0;
  for(int i = 0; i < n; i++){
    e++;
    ap[s[e]]++;
    if(ap[o] && ap[x]){
      while(ap[o] && ap[x]){
        ans += n - e;
        ap[s[b]]--, b++;
      }
    }
  }
  cout << ans << endl;
}