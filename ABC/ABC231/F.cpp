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


// segtree func
int op(int a, int b){
  return a + b;
}
int e(){
  return 0;
}

int main(){
  int n; cin >> n;
  vector<int> a(n), b(n);
  aryin(a, n);
  aryin(b, n);

  // compression
  vector<int> ax(all(a)), bx(all(b));
  sort(all(ax));
  sort(all(bx));
  ax.erase(unique(all(ax)), ax.end());
  bx.erase(unique(all(bx)), bx.end());

  vector<pair<int, int>> p(n);

  for(int i = 0; i < n; i++){
    a[i] = lower_bound(all(ax), a[i]) - ax.begin();
    b[i] = lower_bound(all(bx), b[i]) - bx.begin();
    p[i] = {a[i], b[i]};
  }

  sort(all(p), [](pair<int, int> a, pair<int, int> b){
    if(a.second == b.second){
      return a.first > b.first;
    }else{
      return a.second < b.second;
    }
  });

  segtree<int, op, e> seg(n);

  ll ans = 0;
  int cont = 0;
  for(int i = 0; i < n; i++){
    auto x = p[i];
    if(i){
      if(x.first == p[i - 1].first && x.second == p[i - 1].second){
        cont++;
      }else{
        cont = 0;
      }
    }
    seg.set(x.first, seg.get(x.first) + 1);
    ans += (ll)seg.prod(x.first, n) + cont;
  }

  cout << ans << endl;
}