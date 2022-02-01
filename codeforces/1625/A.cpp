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


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int t; cin >> t;
  query(t){
    int n, l; cin >> n >> l;
    vector<int> x(n);
    aryin(x, n);

    vector<int> vl(l, 0);
    for(int i = 0; i < l; i++){
      for(int j = 0; j < n; j++){
        vl[i] += (x[j] & (1 << i) ? 1 : 0);
      }
    }

    int ans = 0;
    for(int i = 0; i < l; i++){
      if(vl[i] > n / 2){
        ans += 1 << i;
      }
      // if(vl[i] > n - vl[i]){
      //   ans += 1 << i;
      // }
    }

    cout << ans << endl;
  }
}