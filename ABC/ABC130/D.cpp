#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  //
  ll n, k; cin >> n >> k;
  vector<ll> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];

  ll ans = 0;
  ll sum = 0;
  int j = 0;

  for(int i = 0; i < n; i++){
    while(sum < k){
      if(j == n) break;
      else {
        sum += a[j];
        j++;
      }
    }
    if(sum < k)break;
    ans += n - j + 1;
    sum -= a[i];
  }

  cout << ans << endl;

}