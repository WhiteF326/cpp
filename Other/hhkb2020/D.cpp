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
#define query(t) for(int _ = 0; _ < t; _++)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


#define mint modint1000000007
ostream& operator<< (ostream& os, const mint& v){
  os << v.val();
  return os;
}
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int t; cin >> t;
  query(t){
    ll rn, ra, rb; cin >> rn >> ra >> rb;
    if(rn < ra + rb){
      cout << 0 << endl;
      continue;
    }
    if(ra < rb) swap(ra, rb);
    mint n(rn), a(ra), b(rb);

    mint left = (n - a + 1).pow(2) * (n - b + 1).pow(2);

    mint rh = (n - b + 1) * (b - a + 1);
    mint rj = (a - 2) * (a - 2 + 1) / 2;
    rj += (a - 1) * (n - a - b + 2);

    mint ans = left - (rh + rj * 2).pow(2);

    cout << ans.val() << endl;
  }
}