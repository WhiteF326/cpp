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
  
  int n; cin >> n;
  int m; cin >> m;
  
  map<int, vector<int>> p;
  query(m){
    int x, y; cin >> x >> y;
    p[x].push_back(y);
  }

  set<int> st;
  st.insert(n);

  for(auto px : p){
    set<int> a, b;
    for(int y : px.second){
      if(st.find(y - 1) != st.end()) a.insert(y);
      else if(st.find(y + 1) != st.end()) a.insert(y);
      else b.insert(y);
    }
    for(int v : b) st.erase(v);
    for(int v : a){
      if(0 <= v && v <= 2 * n) st.insert(v);
    }
  }
  cout << st.size() << endl;
}
