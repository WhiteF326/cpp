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


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int q; cin >> q;

  // 正, 負
  
  query(q){
    int t; cin >> t;
    if(t == 1){
      ll x; cin >> x;
    }else if(t == 2){
      // x 以下で大きい方から k 番目
      ll x; cin >> x;
      int k; cin >> k;

    }else{
      // x 以上で小さい方から k 番目
      ll x; cin >> x;
      int k; cin >> k;
    }
  }
  fflush(stdout);
}
