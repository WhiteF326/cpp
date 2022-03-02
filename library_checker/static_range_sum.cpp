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


template<class T>
struct CumulativeSum{
public:
  CumulativeSum(const vector<T>& v) : n(int(v.size())){
    cv = vector<T>(n + 1, 0);

    for(int i = 0; i < n; i++){
      cv[i + 1] += cv[i];
      cv[i + 1] += v[i];
    }
  }

  T sum(int l, int r){
    return cv[r] - cv[l - 1];
  }

private:
  int n;
  vector<T> cv;
};
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n, q; cin >> n >> q;
  vector<ll> a(n);
  aryin(a, n);

  CumulativeSum<ll> cm(a);

  query(q){
    int l, r; cin >> l >> r;
    cout << cm.sum(l + 1, r) << "\n";
  }
  fflush(stdout);
}
