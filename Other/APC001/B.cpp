#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  int n; cin >> n;
  vector<ll> a(n), b(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < n; i++) cin >> b[i];

  ll a_b = 0, b_b = 0;
  for(int i = 0; i < n; i++){
    if(a[i] > b[i]) a_b += a[i] - b[i];
    if(b[i] > a[i]) b_b += (b[i] - a[i]) / 2;
  }
  if(b_b >= a_b) cout << "Yes" << endl;
  else cout << "No" << endl;
}