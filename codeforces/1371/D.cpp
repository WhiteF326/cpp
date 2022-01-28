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
    vector<vector<int>> v(n, vector<int>(n, 0));
    vector<int> r(n, 0), c(n, 0);
    for(int i = 0; i < n; i++){
      if(!k) break;
      for(int j = 0; j < n; j++){
        if(!k) break;
        v[j][(j + i) % n] = 1;
        r[j]++;
        c[(j + i) % n]++;
        k--;
      }
    }
    sort(all(r));
    sort(all(c));
    int f = (r[n - 1] - r[0]) * (r[n - 1] - r[0]);
    f += (c[n - 1] - c[0]) * (c[n - 1] - c[0]);
    cout << f << endl;
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        cout << v[i][j];
      }cout << endl;
    }
  }
}