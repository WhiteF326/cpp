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
#define aryin(a, n) for(int i = 0; i < n; i++) ifs >> a[i];

int vis[150009];

int main(){
  ifstream ifs("input.txt");
  
  int t; ifs >> t;
  query(t){
    int n;
    ifs >> n;

    vector<int> a(n);
    aryin(a, n);
    vector<pair<int, int>> v;
    for(int i = 0; i < n; i++){
      v.push_back({a[i], i});
    }
    sort(all(v));

    int l = 0;
    for(int i = 0; i < n - 1; i++){
      if(v[i].first == v[i + 1].first){
        l = max(l, n - v[i + 1].second + v[i].second);
      }
    }
    if(l) cout << l << endl;
    else cout << -1 << endl;
  }
}

// int main(){
//   ifstream ifs("input.txt");
  
//   int t; ifs >> t;
//   query(t){
//     int n; ifs >> n;
//     vector<int> a(n);
//     aryin(a, n);

//     vector<vector<int>> v(150001);
//     for(int i = 0; i < n; i++){
//       v[a[i]].push_back(i);
//     }
//     int ans = 0;
//     for(int i = 1; i <= 150000; i++){
//       if(v[i].size() < 2) continue;
//       for(int j = 0; j < v[i].size() - 1; j++){
//         // cout << v[i][j] << " " << v[i][j + 1] << endl;
//         ans = max(ans, v[i][j] + (n - v[i][j + 1]));
//       }
//     }

//     if(ans) cout << ans << endl;
//     else cout << -1 << endl;
//   }
// }