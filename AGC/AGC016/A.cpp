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
  int n = s.length();
  map<char, int> p;
  for(char c : s) p[c]++;

  int ans = INT_MAX;

  for(auto pr : p){
    char c = pr.first;

    map<char, int> t(all(p));
    int cur = n, res = 0;
    string u = s;
    while(t.size() > 1){
      // cout << u << " " << t.size() << endl;
      res++;
      t.clear();
      string v = u;
      v.pop_back();
      for(int i = 0; i < cur - 1; i++){
        // choose from u[i], u[i + 1]
        if(u[i] == c || u[i + 1] == c){
          v[i] = c;
        }else{
          v[i] = u[i];
        }
        t[v[i]]++;
      }
      u = v;
      cur--;
    }
    ans = min(ans, res);
  }
  cout << ans << endl;
}