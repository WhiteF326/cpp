#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define const constexpr
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


ll gcd(ll x, ll y){
  if(x == 0 || y == 0){
    return max(x, y);
  }
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
  
  int t; cin >> t;
  query(t){
    int n; cin >> n;
    vector<int> v(n);
    aryin(v, n);

    unordered_map<int, int> ctr;
    for(int x : v) ctr[x]++;
    if(ctr.size() < 2){
      cout << -1 << endl;
      continue;
    }

    vector<int> diff(n * n, 0);
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        diff[i * n + j] = abs(v[i] - v[j]);
      }
    }
    sort(all(diff), greater<int>());

    int ans = diff[0];
    for(int i = 0; i < n * n; i++){
      ans = gcd(ans, diff[i]);
    }

    if(ans){
      cout << ans << endl;
    }else{
      cout << -1 << endl;
    }
  }
}