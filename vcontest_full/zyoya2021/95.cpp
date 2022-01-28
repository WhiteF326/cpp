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

  int n; cin >> n;
  vector<int> a(n), d(n);
  aryin(a, n);
 
  sort(all(a), greater<int>());
  int first = a[0];
  for(int i = 0; i < n; i++){
    d[i] = abs(min(a[i] - ceil(first / 2.0), a[i] - floor(first / 2)));
  }
  d[0] = INT_MAX;
  int second = a[min_element(all(d)) - d.begin()];
 
  cout << first << " " << second << endl;
}