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
  
  int h, w, k; cin >> h >> w >> k;
  vector<int> a(h);
  aryin(a, h);
  vector<int> b(w);
  aryin(b, w);

  ll red = k - 1;
  ll reh = (red * w) % k;
  ll rev = (red * h) % k;

  ll hs = 0;
  for(int i = 0; i < h; i++){
    hs += (reh - a[i] + k) % k;
  }
  ll vs = 0;
  for(int i = 0; i < w; i++){
    vs += (rev - b[i] + k) % k;
  }

  if(hs % k != vs % k){
    cout << -1 << endl;
  }else{
    cout << (ll)(k - 1) * h * w - max(hs, vs) << endl;
  }
}