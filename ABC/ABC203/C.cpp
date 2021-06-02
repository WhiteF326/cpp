#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
using ll = long long;
using ld = long double;

int main(){
  ll n, k; cin >> n >> k;
  ll ans = 0, t = 0;
  vector<pair<ll, ll>> friends;
  for(int i = 0; i < n; i++){
    ll a, b; cin >> a >> b;
    friends.push_back(make_pair(a, b));
  }
  sort(friends.begin(), friends.end());
  for(int i = 0; i < n; i++){
    ll a = friends[i].first, b = friends[i].second;
    // 移動量はa - t
    if(a - t > k){
      // 終了
      cout << t + k << endl;
      return 0;
    }else{
      // 移動できる
      k -= a - t;
      t = a;
      k += b;
    }
  }
  // 残金を使う
  cout << t + k << endl;
}