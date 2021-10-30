#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];

using S = long long;
using F = long long;
const S INF = 1e18;
S op(S a, S b){ return std::min(a, b); }
S e(){ return INF; }
S mapping(F f, S x){ return f+x; }
F composition(F f, F g){ return f+g; }
F id(){ return 0; }

int sume(){
  return 0;
}
int sumop(int a, int b){
  return a + b;
}

int main(){
  int n, q; cin >> n >> q;
  string s; cin >> s;
  vector<int> p(n);
  for(int i = 0; i < n; i++) p[i] = (s[i] == '(' ? 1 : -1);
  segtree<int, sumop, sume> sumseg(p);
  lazy_segtree<S, op, e, F, mapping, composition, id> minseg(n);
  for(int i = 0; i < n; i++){
    minseg.set(i, sumseg.prod(0, i + 1));
  }
  
  for(int i = 0; i < q; i++){
    int t, l, r; cin >> t >> l >> r;
    l--;
    if(t == 1){
      r--;
      if(s[l] == s[r]) continue;
      int diff = (s[l] == '(' ? -2 : 2);
      int lb = sumseg.get(l);
      int rb = sumseg.get(r);
      sumseg.set(l, rb);
      sumseg.set(r, lb);
      minseg.apply(l, r, diff);
      swap(s[l], s[r]);
    }else{
      int diff = 0;
      if(l > 0){
        diff = sumseg.prod(0, l);
      }
      if(sumseg.prod(l, r) == 0 && minseg.prod(l, r) - diff >= 0){
        cout << "Yes" << endl;
      }else{
        cout << "No" << endl;
      }
    }
  }
}