#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define const constexpr
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;
#define query(t) for(int _ = 0; _ < t; _++)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


int main(){
  int n; cin >> n;
  vector<ll> a(n), b(n);
  aryin(a, n);
  aryin(b, n);

  vector<ll> diffl(0), diffx(0);

  for(int i = 0; i < n; i++){
    if(a[i] < b[i]) diffl.push_back(b[i] - a[i]);
    else if(a[i] > b[i]) diffx.push_back(a[i] - b[i]);
  }

  ll loss = accumulate(all(diffl), 0LL);
  if(accumulate(all(diffl), 0LL) > accumulate(all(diffx), 0LL)){
    cout << -1 << endl;
    return 0;
  }
  sort(all(diffx), greater<ll>());
  ll ans = diffl.size();
  int pos = 0;
  while(loss > 0){
    loss -= diffx[pos];
    ans++, pos++;
  }
  cout << ans << endl;
}