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
  int n, q; cin >> n >> q;
  dsu d(n);
  query(q){
    int p, a, b; cin >> p >> a >> b;
    if(p){
      cout << (d.same(a, b) ? "Yes" : "No") << endl;
    }else{
      d.merge(a, b);
    }
  }
}