#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
// #define const constexpr
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;
#define query(t) for(int _ = 0; _ < t; _++)


int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q; cin >> n >> q;
  vector<int> c(n);
  for(int i = 0; i < n; i++) cin >> c[i];

  vector<pair<int, int>> qr(q);
  vector<int> ql(q);

  for(int i = 0; i < q; i++){
    int l, r; cin >> l >> r;
    l--;
    qr[i].first = l, qr[i].second = r;
    ql[i] = i;
  }

  int sn = sqrt(n);
  
  sort(all(ql), [&](int i, int j){
    if(qr[i].first / sn != qr[j].first / sn) return qr[i].first < qr[j].first;
    return qr[i].second < qr[j].second;
  });

  vector<int> anslist(q);

  vector<int> cur(n, 0);
  int cl = 0, cr = 0, t = 0;

  for(int i : ql){
    while(cl > qr[i].first){
      cl--;
      if(!cur[c[cl]]) t++;
      cur[c[cl]]++;
    }
    while(cr < qr[i].second){
      if(!cur[c[cr]]) t++;
      cur[c[cr]]++;
      cr++;
    }
    while(cl < qr[i].first){
      cur[c[cl]]--;
      if(!cur[c[cl]]) t--;
      ++cl;
    }
    while(cr > qr[i].second){
      --cr;
      cur[c[cr]]--;
      if(!cur[c[cr]]) t--;
    }

    anslist[i] = t;
  }

  for(int v : anslist) cout << v << endl;
}