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
  
  int n, q; cin >> n >> q;
  string t; cin >> t;

  set<int> st;
  for(int i = 0; i < n; i++){
    if(t[i] == '1') st.insert(i);
  }
  query(q){
    int c, k; cin >> c >> k;
    switch(c){
      case 0:
        st.insert(k);
        break;
      
      case 1:
        if(!(st.find(k) == st.end())) st.erase(st.find(k));
        break;
      
      case 2:
        cout << (st.find(k) != st.end()) << "\n";
        break;
      
      case 3:
        if(*st.rbegin() < k){
          cout << -1 << "\n";
        }else{
          cout << *st.lower_bound(k) << "\n";
        }
        break;
      
      case 4:
        if(st.upper_bound(k) == st.begin()){
          cout << -1 << "\n";
        }else{
          cout << *(--st.upper_bound(k)) << "\n";
        }
        
        break;
    }
  }
  fflush(stdout);
}
