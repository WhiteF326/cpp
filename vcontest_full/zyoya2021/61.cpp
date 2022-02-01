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
  
  int n; cin >> n;
  string s; cin >> s;
  string t = s.substr(0, 2);
 
  for(int i = 2; i < n; i++){
    t += s.substr(i, 1);
    if(t.length() < 3) continue;
    if(t.substr(t.length() - 3, 3) == "fox"){
      for(int j = 0; j < 3; j++){
        t.pop_back();
      }
    }
  }
  cout << t.length() << endl;
}