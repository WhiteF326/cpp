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
  int q; cin >> q;
  bool revflg = false;
  for(int i = 0; i < q; i++){
    int t, a, b; cin >> t >> a >> b;
    if(t == 1){
      a--, b--;
      if(revflg) a = (a + n) % (2 * n), b = (b + n) % (2 * n);
      char t = s[a];
      s[a] = s[b];
      s[b] = t;
    }else{
      revflg = !revflg;
    }
  }
  if(revflg){
    cout << s.substr(n) << s.substr(0, n) << endl;
  }else cout << s << endl;
}