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
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


struct Edge{
  int from;
  int to;
  ll cost;
};
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n, m; cin >> n >> m;
  vector<ll> w(n);
  aryin(w, n);

  vector<ll> l(m), v(m);
  for(int i = 0; i < m; i++) cin >> l[i] >> v[i];

  // unable
  if(*max_element(all(w)) > *min_element(all(v))){
    cout << -1 << endl;
    return 0;
  }

  sort(all(w));

  vector<ll> dist(1 << n, 0);
  for(int bit = 0; bit < (1 << n); bit++){
    ll wx = 0;
    for(int i = 0; i < n; i++){
      if(bit & (1 << i)) wx += w[i];
    }
    for(int j = 0; j < m; j++){
      if(v[j] < wx){
        dist[bit] = max(dist[bit], l[j]);
      }
    }
  }

  vector<int> p(n);
  for(int i = 0; i < n; i++) p[i] = i;

  ll ans = INT_MAX;

  do{
    vector<ll> dp(n, 0);
    for(int i = 1; i < n; i++){
      int bit = (1 << p[i]);
      for(int j = i - 1; j >= 0; j--){
        bit |= (1 << p[j]);
        dp[i] = max(dp[i], dp[j] + dist[bit]);
      }
    }

    ans = min(ans, dp[n - 1]);
  }while(next_permutation(all(p)));

  cout << ans << endl;
}