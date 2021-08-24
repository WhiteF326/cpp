#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define const constexpr
#define pdesc(t) t, vector<t>, greater<t>
#define chmin(a, b) a = min(a, b)
using ll = long long;
using ld = long double;

int op(int a, int b){
  return max(a, b);
}
int e(){
  return 0;
}

int main(){
  int n, k; cin >> n >> k;
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  segtree<int, op, e> seg(n);

  for(int i = 0; i < n; i++){
    int l = max(0, a[i] - k);
    int r = min(500000, a[i] + k + 1);
    int v = seg.prod(l, r);
    seg.set(a[i], v + 1);
  }
  cout << seg.all_prod() << endl;
}