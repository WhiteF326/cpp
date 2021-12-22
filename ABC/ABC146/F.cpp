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


int INF = INT_MAX;
struct cell{
  int depth;
  int from;
};
cell op(cell a, cell b){
  if(a.depth <= b.depth){
    return a;
  }else{
    return b;
  }
}
cell e(){
  return {INF, INF};
}
cell mapping(cell f, cell x){
  if(f.depth <= x.depth){
    return f;
  }else{
    return x;
  }
}
cell composition(cell f, cell g){
  if(f.depth <= g.depth){
    return f;
  }else{
    return g;
  }
}
cell id(){
  return {INF, INF};
}
int main(){
  int n, m; cin >> n >> m;
  string s; cin >> s;
  reverse(all(s));

  lazy_segtree<cell, op, e, cell, mapping, composition, id> seg(n + 1);

  seg.apply(0, {0, 0});

  for(int i = 0; i < n + 1; i++){
    if(s[i] == '1' || seg.get(i).from == INF) continue;
    auto x = seg.get(i);
    seg.apply(i, min(i + m + 1, n + 1), {x.depth + 1, i});
  }

  if(seg.get(n).from == INF){
    cout << -1 << endl;
    return 0;
  }

  vector<int> frm(n + 1);
  for(int i = 0; i < n + 1; i++) frm[i] = seg.get(i).from;

  int cur = 0, pos = 0;
  stack<int> anslist;
  while(true){
    pos = upper_bound(all(frm), cur) - frm.begin() - 1;
    while(s[pos] == '1') pos--;

    anslist.push(pos - cur);
    cur = pos;

    if(pos >= n) break;
  }

  while(!anslist.empty()){
    cout << anslist.top() << " ";
    anslist.pop();
  }
}