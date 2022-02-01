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
  
  int n, k; cin >> n >> k;
  vector<ll> v(n);
  aryin(v, n);

  if(*min_element(all(v)) == 0){
    cout << n << endl;
    return 0;
  }

  int ans = 0;
  deque<ll> dq;
  ll prod = 1;

  for(ll d : v){
    dq.push_back(d);
    prod *= d;

    while(!dq.empty() && prod > k){
      ll rem = dq.front();
      dq.pop_front();

      prod /= rem;
    }

    ans = max(ans, (int)dq.size());
  }

  cout << ans << endl;
}