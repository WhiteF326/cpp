#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j)
using ll = long long;
using ld = long double;

int main(){
  ll n, k; cin >> n >> k;
  map<int, ll> a;
  for(int i = 0; i < n; i++){
    int x; cin >> x;
    a[x]++;
  }

  ll ans = 0;
  for(int x = 0; x < k; x++){
    for(int i = 0; i <= 300001; i++){
      if(a[i] > 0){
        a[i]--;
      }else{
        ans += (ll)i;
        break;
      }
    }
  }
  cout << ans << endl;
}