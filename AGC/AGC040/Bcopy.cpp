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


class Range{
  public:
    int l;
    int r;
  
  Range(int l, int r){
    this->l = l;
    this->r = r;
  }

  Range(){
    l = 0;
    r = 1000000001;
  }

  int dist(){
    return max(0, r - l + 1);
  }

  string toString(){
    return "[" + to_string(l) + ", " + to_string(r) + "]";
  }
};

Range op(Range a, Range b){
  return Range(max(a.l, b.l), min(a.r, b.r));
}
Range e(){
  return Range(0, 1000000001);
}

int main(){
  ifstream ifs("test.txt");
  int n; ifs >> n;
  vector<pair<int, int>> a(n);
  vector<Range> r(n);

  for(int i = 0; i < n; i++){
    int l, r; ifs >> l >> r;
    a[i] = mp(l, r);
  }
  
  sort(all(a), [](pair<int, int> a, pair<int, int> b){
    if(a.first == b.first) return a.second > b.second;
    else return a.first < b.first;
  });

  segtree<Range, op, e> seg(n);
  for(int i = 0; i < n; i++){
    seg.set(i, Range(a[i].first, a[i].second));
  }

  int lim = a[0].second;

  int ans = 0;
  for(int i = 0; i < n - 1; i++){
    if(a[i].first > lim) break;
    int res = seg.prod(0, i + 1).dist() + seg.prod(i + 1, n).dist();
    // cout << seg.prod(0, i + 1).toString() << " " << seg.prod(i + 1, n).toString() << endl;
    ans = max(ans, res);
  }

  for(int i = 0; i < n; i++){
    auto v = seg.get(i);
    seg.set(i, Range());
    int res = v.dist() + seg.all_prod().dist();
    seg.set(i, v);
    ans = max(ans, res);
  }

  cout << ans << endl;
}