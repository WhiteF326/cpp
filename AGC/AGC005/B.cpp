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
  vector<pair<ll, ll>> v(n);
  for(int i = 0; i < n; i++){
    cin >> v[i].first;
    v[i].second = i;
  }

  /**
   * 主客転倒。多分、小さい方から入れていけば OK
  */
  set<int> st;
  st.insert(-1);
  st.insert(n);

  sort(all(v));

  ll ans = 0;

  for(int i = 0; i < n; i++){
    int dst = v[i].second;
    auto itr = st.lower_bound(dst);
    int r = *itr;
    itr = prev(itr);
    int l = *itr;

    ans += (ll)v[i].first * (ll)(r - dst) * (ll)(dst - l);

    st.insert(dst);
  }

  cout << ans << endl;
}
