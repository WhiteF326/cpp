#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
using ll = long long;
using ld = long double;

int main(){
  int n; cin >> n;
  ll m = 1000;
  
  vector<ll> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];

  for(int i = 0; i < n - 1; i++){
    if(a[i] < a[i + 1]){
      ll b = m / a[i];
      m -= a[i] * b;
      m += a[i + 1] * b;
    }
  }
  cout << m << endl;
}