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
    int n, k; cin >> n >> k;
    int ans = INT_MAX;
    for(int i = 1; i * i <= n; i++){
      if(n % i == 0){
        // try i
        if(i <= k){
          ans = min(ans, n / i);
        }
        // try n / i
        if(n / i <= k){
          ans = min(ans, i);
        }
      }
    }

    cout << ans << endl;
  }
}