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
    ll n, r; cin >> n >> r;
    if(n > r){
      ll ans = r * (r + 1) / 2;
      cout << ans << endl;
    }else{
      ll ans = n * (n - 1) / 2 + 1;
      cout << ans << endl;
    }
  }
}