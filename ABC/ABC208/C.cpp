#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  ll n, k; cin >> n >> k;
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  map<int, ll> x;
  for(int i = 0; i < n; i++){
    x[a[i]] = k / n;
  }
  k = k % n;
  for(auto v = x.begin(); v != x.end(); v++){
    if(k == 0) break;
    v->second++;
    k--;
  }
  for(auto s : a){
    cout << x[s] << endl;
  }
}