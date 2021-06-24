#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
using ll = long long;
using ld = long double;

ll gcd(ll x, ll y){
  while(y > 0){
    ll r = x % y;
    x = y;
    y = r;
  }
  return x;
}

int main(){
  int n, q; cin >> n >> q;
  int shifted = 0;
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < q; i++){
    int t, x, y; cin >> t >> x >> y;
    x--, y--;
    switch(t){
      case 1:
        swap(a[(x + shifted) % n], a[(y + shifted) % n]);
        break;
      case 2:
        shifted += n - 1;
        shifted %= n;
        break;
      case 3:
        cout << a[(x + shifted) % n] << endl;
        break;
    }
  }
}