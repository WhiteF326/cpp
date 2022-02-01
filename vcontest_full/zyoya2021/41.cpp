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

  int h, w; cin >> h >> w;
  int c; cin >> c;
  int q; cin >> q;

  vector<int> t(q), p(q), col(q);

  for(int i = 0; i < q; i++){
    cin >> t[i] >> p[i] >> col[i];
  }

  vector<ll> ccl(c + 1, 0);

  set<int> ver, hor;
  for(int i = q - 1; i >= 0; i--){
    if(t[i] == 1){
      if(hor.find(p[i]) != hor.end()) continue;
      ccl[col[i]] += w - ver.size();
      hor.insert(p[i]);
    }else{
      if(ver.find(p[i]) != ver.end()) continue;
      ver.insert(p[i]);
      ccl[col[i]] += h - hor.size();
    }
  }

  for(int i = 1; i <= c; i++){
    cout << ccl[i] << " ";
  }cout << endl;
}