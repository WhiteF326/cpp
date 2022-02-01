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
  
  int tt; cin >> tt;
  query(tt){
    int n, k; cin >> n >> k;
    vector<pair<int, int>> v(n);
    for(int i = 0; i < n; i++) cin >> v[i].first;
    for(int i = 0; i < n; i++) cin >> v[i].second;

    sort(all(v));

    for(int i = 0; i < n; i++){
      if(v[i].first > k) break;
      k += v[i].second;
    }
    cout << k << endl;
  }
}