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
  ll l = -1e15;
  ll r = 1e15;

  for(int i = 0; i < n; i++){
    ll lx, rx; cin >> lx >> rx;
    l = max(l, lx);
    r = min(r, rx);

    if(l <= r){
      cout << 0 << endl;
    }else{
      cout << (ll)ceil(abs(l - r) / 2.0) << endl;
    }
  }
}
