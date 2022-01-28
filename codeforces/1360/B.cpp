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
    int n; cin >> n;
    vector<int> v(n);
    aryin(v, n);
    
    sort(all(v));
    int ans = INT_MAX;
    for(int i = 0; i < n - 1; i++){
      ans = min(ans, v[i + 1] - v[i]);
    }

    cout << ans << endl;
  }
}