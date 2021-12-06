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
  int n, m; cin >> n >> m;
  vector<vector<int>> g(n);
  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    g[a - 1].push_back(b - 1);
  }

  vector<int> cur(n, 0);

  stack<int> st;
  set<int> s;
  for(int i = n - 1; i >= 1; i--){
    s.insert(i);
    cur[i] = i;
    for(int v : g[i]){
      s.erase(cur[v]);
      cur[v] = i;
    }
    st.push(s.size());
  }

  for(int i = 0; i < n - 1; i++){
    cout << st.top() << endl;
    st.pop();
  }
  cout << 0 << endl;
}