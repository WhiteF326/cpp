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
#define query(t) for(int qqqqqqq = 0; qqqqqqq < t; qqqqqqq++)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


int main(){
  int k, q; cin >> k >> q;
  vector<int> d(k); aryin(d, k);
  
  query(q){
    int n, x, m; cin >> n >> x >> m;
    // k + 1 回未満なら愚直に
    if(n < k + 1){
      // 頑張る
    }else{
      // 
    }
  }
}