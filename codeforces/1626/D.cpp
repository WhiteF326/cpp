#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

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
  
  int t; cin >> t;
  auto dest = [](int p){
    if(p == 0) return 1;
    if(p == 1) return 1;
    return 1 << (int)ceil(log2(p));
  };
  query(t){
    int n; cin >> n;
    vector<int> a(n);
    aryin(a, n);
    sort(all(a));
    
    int ans = INT_MAX;
    for(int i = 0; i < n; i++){
      int res = 0;

      int f = lower_bound(all(a), a[i]) - a.begin();
      res += dest(f) - f;

      int sv = 0;
      while(f + sv < n){
        int s = lower_bound(all(a), a[f + sv]) - a.begin();
        s -= f;
        res += dest(f) - f;

        int t = n - f - s;
        res += dest(t) - t;
        if(!sv){
          sv = 1;
        }else{
          sv <<= 1;
        }

        ans = min(ans, res);
      }
    }
  }
  fflush(stdout);
}