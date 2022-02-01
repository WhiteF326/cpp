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
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;
#define query(t) for(int _ = 0; _ < t; _++)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n, q; cin >> n >> q;
  dsu d(2 * n);

  query(q){
    int w; cin >> w;
    int x, y, z; cin >> x >> y >> z;
    x--, y--;
    if(w == 1){
      // unite
      if(z % 2){
        d.merge(2 * x, 2 * y + 1);
        d.merge(2 * x + 1, 2 * y);
      }else{
        d.merge(2 * x, 2 * y);
        d.merge(2 * x + 1, 2 * y + 1);
      }
    }else{
      // ask
      if(d.same(2 * x, 2 * y)){
        cout << "YES" << endl;
      }else{
        cout << "NO" << endl;
      }
    }
  }
}