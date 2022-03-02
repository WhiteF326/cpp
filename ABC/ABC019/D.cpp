#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define all(x) x.begin(), x.end()
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;
#define query(t) for(int _ = 0; _ < t; _++)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n; cin >> n;
  int p = 0;
  vector<int> a(n);
  for(int i = 0; i < n; i++){
    if(p == i) continue;
    cout << "? " << p + 1<< " " << i + 1 << endl;
    cin >> a[i];
  }
  int d = max_element(all(a)) - a.begin();
  fill(all(a), 0);
  for(int i = 0; i < n; i++){
    if(d == i) continue;
    cout << "? " << d + 1<< " " << i + 1 << endl;
    cin >> a[i];
  }
  cout << "! " << *max_element(all(a));
}
