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
    vector<int> a(n);
    aryin(a, n);

    vector<vector<int>> v(150001);
    for(int i = 0; i < n; i++){
      v[a[i]].push_back(i);
    }
    int ans = 0;
    for(int i = 1; i <= 150000; i++){
      if(v[i].size() < 2) continue;
      for(int j = 0; j < v[i].size() - 1; j++){
        // cout << v[i][j] << " " << v[i][j + 1] << endl;
        ans = max(ans, v[i][j] + (n - v[i][j + 1]));
      }
    }

    if(ans) cout << ans << endl;
    else cout << -1 << endl;
  }
}