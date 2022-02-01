#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  string s, t; cin >> s >> t;
  map<char, int> sp, tp;
  vector<int> sl(s.length()), tl(t.length());

  for(int i = 0; i < s.length(); i++){
    if(sp[s[i]]) sl[i] = sp[s[i]];
    else{
      sl[i] = sp.size();
      sp[s[i]] = sp.size();
    }
  }
  for(int i = 0; i < t.length(); i++){
    if(tp[t[i]]) tl[i] = tp[t[i]];
    else{
      tl[i] = tp.size();
      tp[t[i]] = tp.size();
    }
  }
  
  for(int i = 0; i < s.length(); i++){
    if(sl[i] != tl[i]){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}