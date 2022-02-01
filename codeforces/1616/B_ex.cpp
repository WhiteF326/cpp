#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define const constexpr
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int t; cin >> t;
  query(t){
    int n; cin >> n;
    string s; cin >> s;
    string t = "", u = "";
    set<string> st;
    for(int i = 0; i < n; i++){
      t += s[i];
      u = s[i] + u;
      st.insert(t + u);
    }
    
    cout << *st.begin() << endl;
  }
}