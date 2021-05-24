#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  // 先に階乗%1000000007を求めておく
  vector<ll> factList(10001, 1);
  for(int i = 2; i < 10001; i++){
    factList[i] = factList[i - 1] * i;
    factList[i] %= 1000000007;
  }
  int n; cin >> n;
  vector<ll> t(n);
  map<ll, int> appearance;
  for(int i = 0; i < n; i++){
    cin >> t[i];
    appearance[t[i]]++;
  }
  sort(t.begin(), t.end());

  vector<ll> penalty(n, 0);
  penalty[0] = t[0];
  for(int i = 1; i < n; i++) penalty[i] = penalty[i - 1] + t[i];
  cout << accumulate(penalty.begin(), penalty.end(), 0LL) << endl;
  ll ans = 1;
  for(auto itr = appearance.begin(); itr != appearance.end(); itr++){
    ans *= factList[itr->second];
    ans %= 1000000007;
  }
  cout << ans << endl;
}