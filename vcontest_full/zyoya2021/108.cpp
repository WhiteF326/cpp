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


ll gcd(ll x, ll y){
  while(y > 0){
    ll r = x % y;
    x = y;
    y = r;
  }
  return x;
}
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n, k; cin >> n >> k;
  vector<int> a(n);
  aryin(a, n);
  
  int g = a[0];
  for(int v : a) g = gcd(g, v);

  if(*max_element(all(a)) >= k && k % g == 0){
    cout << "POSSIBLE" << endl;
  }else{
    cout << "IMPOSSIBLE" << endl;
  }
}