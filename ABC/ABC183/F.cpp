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
  int n, q; cin >> n >> q;
  vector<map<int, int>> m(n);
  for(int i = 0; i < n; i++){
    int c; cin >> c;
    m[i][c - 1] = 1;
  }

  dsu d(n);
  query(q){
    int t, x, y; cin >> t >> x >> y;
    x--, y--;
    if(t == 1){
      x = d.leader(x);
      y = d.leader(y);
      if(x != y){
        d.merge(x, y);
        if(d.leader(x) != x) swap(x, y);
        for(auto p : m[y]){
          m[x][p.first] += p.second;
        }
      }
    }else{
      cout << m[d.leader(x)][y] << endl;
    }
  }
}