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
  
  ll n; cin >> n;
  ll ans = 0;
  for(int i = 1; i <= 15; i++){
    string s = "";
    for(int j = 0; j < i; j++) s += "1";
    ll st = stoll(s);

    if(st > n) break;
    else ans++;
    ll bt = st;
    ll tp = st;

    while(1){
      bt *= 10LL;
      tp = (tp + 1LL) * 10LL - 1LL;

      if(n < bt) break;

      ans += min(n, tp) - bt + 1;
    }
  }

  cout << ans << endl;
}