#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define const constexpr
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;
#define query(t) for(int _ = 0; _ < t; _++)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


int main(){
  string s; cin >> s;
  string t; cin >> t;

  vector<string> anslist(0);

  if(s.length() < t.length()){
    cout << "UNRESTORABLE" << endl;
    return 0;
  }

  for(int i = 0; i <= s.length() - t.length(); i++){
    bool flg = true;
    for(int j = 0; j < t.length(); j++){
      if(s[i + j] == '?') continue;
      if(s[i + j] != t[j]) flg = false;
    }
    if(flg){
      string u = s;
      for(int j = 0; j < t.length(); j++){
        u[i + j] = t[j];
      }
      for(char &c : u){
        if(c == '?') c = 'a';
      }
      anslist.push_back(u);
    }
  }

  if(anslist.size() == 0) cout << "UNRESTORABLE" << endl;
  else{
    sort(all(anslist));
    cout << anslist[0] << endl;
  }
}
