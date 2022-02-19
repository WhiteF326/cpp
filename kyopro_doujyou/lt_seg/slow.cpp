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
  
  int n, q; cin >> n >> q;
  vector<int> v(n, 1);
  
  query(q){
    int t, l, r; cin >> t >> l >> r;
    if(t == 1){
      for(int i = l; i <= r; i++){
        v[i - 1]++;
      }
    }else{
      int x = 0;
      for(int i = l; i <= r; i++){
        chmax(x, v[i - 1]);
      }
      for(int i = l; i <= r; i++){
        if(v[i - 1] == x){
          cout << i << endl;
          break;
        }
      }
    }
  }
}
