#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j);
using ll = long long;
using ld = long double;

const ll modv = 1000000007;

int main(){
  int k, t; cin >> k >> t;
  vector<int> a(t, 0);
  for(int i = 0; i < t; i++) cin >> a[i];

  sort(a.begin(), a.end(), greater<int>());
  int ans = a[0];
  for(int i = 1; i < t; i++){
    ans -= a[i];
  }
  ans--;
  cout << max(ans, 0) << endl;
}