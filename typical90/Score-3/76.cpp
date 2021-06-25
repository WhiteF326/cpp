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
  vector<ll> a(n * 2);
  ll sum = 0;
  for(int i = 0; i < n; i++){
    cin >> a[i];
    sum += a[i];
    a[i + n] = a[i];
  }
  int l = 0, r = 0;
  ll t = a[0];
  while(true){
    if(t * 10 == sum){
      cout << "Yes" << endl;
      return 0;
    }
    r++;
    if(r >= n * 2) break;
    t += a[r];
    if(t * 10 > sum){
      t -= a[l];
      l++;
    }
  }
  cout << "No" << endl;
}