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
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n; cin >> n;
  ll k; cin >> k;

  vector<ll> a(n);
  aryin(a, n);

  // test
  ll res = 0;
  for(int i = 0; i < k; i++){
    res += a[res % n];
    cout << res << endl;
  }
  cout << res << endl;
  // end test

  // doubling[v][i] = i 番目にいて 2^k 手後の飴の個数
  vector<vector<ll>> doubling(45, vector<ll>(n, 0));
  for(int i = 0; i < n; i++){
    doubling[0][i] = a[i];
  }
  int lk = 1;
  while((1LL << lk) <= k) lk++;
  for(int v = 0; v < lk - 1; v++){
    for(int i = 0; i < n; i++){
      doubling[v + 1][i] += doubling[v][i];
      doubling[v + 1][i] += doubling[v][doubling[v][i] % n];
    }
  }
  for(int i = 0; i < lk; i++){
    for(int j = 0; j < n; j++){
      cout << doubling[i][j] << " ";
    }cout << endl;
  }

  ll ans = 0;
  vector<bool> move(45, 0);
  for(int i = 0; i <= lk; i++){
    if(k & (1LL << i)) move[i] = 1;
  }
  for(int i = lk; i >= 0; i--){
    if(move[i]) ans += doubling[i][ans % n];
  }
  cout << ans << endl;
}
