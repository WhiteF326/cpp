#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j);
using ll = long long;
using ld = long double;

int main(){
  int n; cin >> n;
  vector<int> a(n), b(n), c(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  for(int i = 0; i < n; i++) cin >> b[i];
  sort(b.begin(), b.end());
  for(int i = 0; i < n; i++) cin >> c[i];
  sort(c.begin(), c.end());

  // bについて2分探索
  vector<int> b_list(n);
  for(int i = 0; i < n; i++){
    int left = -1;
    int right = n;
    while(right - left > 1){
      int mid = left + (right - left) / 2;
      if(c[mid] >= b[i]) right = mid;
      else left = mid;
    }
    b_list[i] = right;
  }

  // 累積和
  vector<int> b_acc(n);
  b_acc[0] = b_list[0];
  for(int i = 1; i < n; i++) b_acc[i] = b_acc[i - 1] + b_list[i];
  ll ans = 0;
  // aについて2分探索
  for(int i = 0; i < n; i++){
    int left = -1;
    int right = n;
    while(right - left > 1){
      int mid = left + (right - left) / 2;
      if(b[mid] >= a[i]) right = mid;
      else left = mid;
    }
    ans += b_acc[right];
  }
  cout << ans << endl;

}