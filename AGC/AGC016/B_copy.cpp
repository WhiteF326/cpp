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
#define aryin(a, n) for(int i = 0; i < n; i++) ifs >> a[i];
#define chmin(a, b) a = min(a, b)


int op(int a, int b){
  return min(a, b);
}
int e(){
  return 100000000;
}
int mapping(int f, int x){
  return f + x;
}
int composition(int f, int g){
  return f + g;
}
int id(){
  return 0;
}

int main(){
  ifstream ifs("1_04.txt");
  int n; ifs >> n;
  vector<int> a(n); aryin(a, n);

  vector<int> lst(n, n - 1), nxt(n, 0);
  for(int i = 0; i < n; i++) nxt[i] = (i + 1) % n;
  vector<bool> h(n, false);

  lazy_segtree<int, op, e, int, mapping, composition, id> seg(lst);

  auto cr = [&](int a){
    return (a + 1) % n;
  };

  for(int i = 0; i < n; i++){
    // 次の頂点
    // for(int j = 0; j < n; j++){
    //   cout << seg.prod(j, j + 1) << " ";
    // }cout << endl;
    int lm = seg.prod(i, i + 1);
    // if(a[i] > lm){
    //   cout << "No" << endl;
    //   return 0;
    // }
    for(int j = 0; j < lm - a[i]; j++){
      // merge ((i + 1), nxt[i + 1])
      if(cr(i) == nxt[cr(i)]){
        // もう繋ぐ頂点がない
        cout << "No" << endl;
        return 0;
      }
      seg.apply(0, n, -1);
      // まだ独立な頂点なら減らさない
      if(!h[cr(i)]){
        h[cr(i)] = true;
        seg.apply(cr(i), cr(i) + 1, 1);
      }
      if(!h[nxt[cr(i)]]){
        h[nxt[cr(i)]] = true;
        seg.apply(nxt[cr(i)], nxt[cr(i)] + 1, 1);
      }
      // 次に繋ぐ頂点にする
      nxt[cr(i)] = cr(nxt[cr(i)]);
    }
  }

  cout << "Yes" << endl;
}