#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n; cin >> n;
  vector<vector<int>> g(n);
  vector<ll> tl(n);
  for(int i = 0; i < n; i++){
    cin >> tl[i];
    int k; cin >> k;
    for(int j = 0; j < k; j++){
      int a; cin >> a;
      g[i].push_back(a - 1);
    }
  }

  ll ans = 0;
  vector<bool> visited(n, false);
  visited[n - 1] = true;
  for(int i = n - 1; i >= 0; i--){
    if(!visited[i]) continue;
    ans += tl[i];
    for(int v : g[i]) visited[v] = true;
  }

  cout << ans << endl;
}