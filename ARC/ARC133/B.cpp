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


int op(int a, int b){
  return max(a, b);
}
int e(){
  return 0;
}
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n; cin >> n;
  vector<int> p(n);
  aryin(p, n);
  vector<int> q(n);
  aryin(q, n);

  vector<int> pc(n + 1);
  for(int i = 0; i < n; i++) pc[p[i]] = i;

  segtree<int, op, e> seg(n);
  for(int i = 0; i < n; i++){
    set<int, greater<int>> st;
    for(int j = 1; j * j <= q[i]; j++){
      if(q[i] % j) continue;
      st.insert(pc[j]);
      st.insert(pc[q[i] / j]);
    }
    for(int s : st){
      seg.set(s, seg.prod(0, s) + 1);
    }
  }
  cout << seg.all_prod() << endl;
}