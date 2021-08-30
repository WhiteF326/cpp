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

int main(){
  int n; cin >> n;
  vector<ll> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];

  int left = 0, right = 0;
  ll sum = a[0], sxor = a[0];
  ll ans = 0;
  while(left < n){
    while(sum == sxor && right < n){
      right++;
      sum += a[right];
      sxor ^= a[right];
    }
    ans += right - left;
    if(left == right && right < n) right++;
    else{
      sum -= a[left];
      sxor ^= a[left];
    }
    left++;
  }
  cout << ans << endl;
}