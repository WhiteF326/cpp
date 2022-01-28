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
#define query(t) for(int _ = 0; _ < t; _++)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  ll n, k; cin >> n >> k;
  k--;
  vector<ll> a(n), b(n);
  aryin(a, n);
  aryin(b, n);

  sort(all(a));
  sort(all(b));

  ll left = 0, right = 1000000000000000000;
  ll mid = 0;

  while(right - left > 1){
    mid = left + (right - left) / 2;
    // mid より大きい値が n^2 - k 個以上出来てしまうか？
    ll ctr = 0;
    for(int i = 0; i < n; i++){
      ll div = mid / a[i];
      ctr += b.end() - upper_bound(all(b), div);
    }

    if(ctr >= n * n - k){
      left = mid;
    }else{
      right = mid;
    }
  }

  cout << left + 1 << endl;
}