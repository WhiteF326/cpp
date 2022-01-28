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
  query(t){
    int n, k; cin >> n >> k;
    vector<int> a(n);
    aryin(a, n);

    vector<vector<int>> dsc(n + 1);
    for(int i = 0; i < n; i++){
      if(dsc[a[i]].size() < k) dsc[a[i]].push_back(i);
    }

    int m = 0;
    for(auto d : dsc) m += d.size();

    m -= m % k;

    int c = 0;
    vector<int> ans(n, 0);
    for(auto d : dsc){
      for(int v : d){
        c++;
        ans[v] = c;
        c %= k;
        m--;
        if(!m) break;
      }
      if(!m) break;
    }

    for(int v : ans) cout << v << " ";
    cout << endl;
  }
}