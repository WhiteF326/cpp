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
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n, m; cin >> n >> m;
  vector<string> s(n);
  for(int i = 0; i < n; i++){
    cin >> s[i];
  }
  set<string> st;
  for(int i = 0; i < m; i++){
    string t; cin >> t;
    st.insert(t);
  }

  for(int i = 0; i < n; i++){
    if(st.find(s[i]) != st.end()){
      cout << "Yes" << endl;
    }else{
      cout << "No" << endl;
    }
  }
}