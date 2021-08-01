#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  int q; cin >> q;
  assert(1 <= q && q <= 200000);
  for(int i = 0; i < q; i++){
    ll a; cin >> a;
    assert(1 <= a && a <= 1e+18);
    stack<ll> d;
    ll f = 1;
    while(a){
      d.push(a % f);
      a /= f;
      f++;
    }
    cout << d.size() - 1<< " ";
    while(d.size() > 1){
      cout << d.top() << " ";
      d.pop();
    }
    cout << endl;
  }
}