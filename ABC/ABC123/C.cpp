#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
using ll = long long;
using ld = long double;

int main(){
  ll n; cin >> n;
  vector<ll> a(5);
  for(int i = 0; i < 5; i++) cin >> a[i];

  ll el = *min_element(a.begin(), a.end());

  cout << 4 + (n + el - 1) / el << endl;
}