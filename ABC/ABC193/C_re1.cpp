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
  
  ll n; cin >> n;
  set<ll> st;
  // count all number that can be expressed as a^b where a,b >= 2 and a^b <= n
  for(ll a = 2; a * a <= n; a++){
    for(ll b = 2; pow(a, b) <= n; b++){
      if(pow(a, b) <= n) st.insert(pow(a, b));
    }
  }

  cout << n - st.size() << endl;
}
