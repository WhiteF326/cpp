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


// segtree func
int op(int a, int b){
  return a + b;
}
int e(){
  return 0;
}

int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n; cin >> n;
  vector<int> a(n), b(n);
  vector<pair<int, int>> p(n);
  for(int i = 0; i < n; i++){
    int x; cin >> x;
    p[i].first = x;
    a[i] = x;
  }
  for(int i = 0; i < n; i++){
    int x; cin >> x;
    p[i].second = x;
    b[i] = x;
  }

  // compression
  sort(all(a));
  sort(all(b));
  a.erase(unique(all(a)), a.end());
  b.erase(unique(all(b)), b.end());

  for(int i = 0; i < n; i++){
    p[i].first = lower_bound(all(a), p[i].first) - a.begin();
    p[i].second = lower_bound(all(b), p[i].second) - b.begin();
  }

  sort(all(p), [](const pair<int, int>& a, const pair<int, int>& b){
    if(a.second == b.second){
      return a.first > b.first;
    }else{
      return a.second < b.second;
    }
  });

  segtree<int, op, e> seg(n);

  ll ans = 0;
  int cont = 0;
  for(int i = 0; i < n; i++){
    auto x = p[i];
    if(i){
      if(x.first == p[i - 1].first && x.second == p[i - 1].second){
        cont++;
      }else{
        cont = 0;
      }
    }
    seg.set(x.first, seg.get(x.first) + 1);
    ans += (ll)seg.prod(x.first, n) + cont;
  }

  cout << ans << endl;
}