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
  int t; cin >> t;
  query(t){
    int n; cin >> n;
    string s; cin >> s;
    string t = s.substr(0, 1);

    set<string> st;

    for(int i = 1; i < n; i++){
      if(s[i - 1] > s[i]){
        t += s[i];
      }else{
        break;
      }
    }
    string v = t;
    reverse(all(t));
    v += t;
    st.insert(v);

    t = s.substr(0, 1);
    v = "";

    for(int i = 1; i < n; i++){
      if(s[i - 1] >= s[i]){
        t += s[i];
      }else{
        break;
      }
    }
    v = t;
    reverse(all(t));
    v += t;
    st.insert(v);

    cout << *st.begin() << endl;
  }
}