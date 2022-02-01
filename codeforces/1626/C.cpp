#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

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

  auto isum = [](ll p){
    return p * (p + 1) / 2LL;
  };
  
  int tt; cin >> tt;
  query(tt){
    int n; cin >> n;
    vector<ll> k(n);
    aryin(k, n);
    vector<ll> h(n);
    aryin(h, n);

    vector<pair<ll, ll>> segm(n);
    for(int i = 0; i < n; i++){
      segm[i] = {k[i] - h[i] + 1, k[i]};
    }
    sort(all(segm), [](const pair<ll, ll>& a, const pair<ll, ll>& b){
      if(a.first == b.first){
        return a.second > b.second;
      }else{
        return a.first < b.first;
      }
    });

    int cur = 0;
    ll ans = 0;
    for(int i = 0; i < n; i++){
      if(cur < segm[i].first){
        cur = segm[i].first;
      }
      if(cur <= segm[i].second){
        ans += isum(segm[i].second - cur + 1LL);
        cur = segm[i].second;
      }
    }

    cout << ans << endl;
  }
}