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
  
  int n; cin >> n;
  vector<ll> a(n); aryin(a, n);

  sort(all(a));
  
  vector<ll> asum(all(a));
  for(int i = 1; i < n; i++) asum[i] += asum[i - 1];

  int ok = -1, ng = n;
  int mid = 0;

  while(ng - ok > 1){
    mid = (ok + ng) / 2;
    int size = 1;
    // cout << "mid: " << mid << endl;
    ll cur = a[mid];
    bool flg = false;
    while(true){
      int x = upper_bound(all(a), cur * 2) - a.begin();
      // cout << cur * 2 << " " << x << " " << size << endl;
      if(x == n){
        flg = true;
        break;
      }else{
        if(x == size) break;
        else{
          cur = asum[x - 1];
          size = x;
        }
      }
    }

    if(flg){
      ng = mid;
    }else{
      ok = mid;
    }
  }

  cout << n - ng << endl;
}