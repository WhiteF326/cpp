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


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n, k, l; cin >> n >> k >> l;
  dsu d(n), e(n);

  for(int i = 0; i < k; i++){
    int a, b; cin >> a >> b;
    d.merge(a - 1, b - 1);
  }
  for(int i = 0; i < l; i++){
    int a, b; cin >> a >> b;
    e.merge(a - 1, b - 1);
  }

  map<ll, int> rc;
  for(int i = 0; i < n; i++){
    rc[(ll)d.leader(i) * n + e.leader(i)]++;
  }
  for(int i = 0; i < n; i++){
    cout << rc[(ll)d.leader(i) * n + e.leader(i)] << " ";
  }cout << endl;
}