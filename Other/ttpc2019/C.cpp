#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j);
using ll = long long;
using ld = long double;

int main(){
  ll n, x; cin >> n >> x;
  ll last = x;
  vector<ll> lostcnt;
  vector<ll> a(n, 0);
  for(ll i = 0; i < n; i++){
    ll s; cin >> s;
    a[i] = s;
    if(s != -1) last = last ^ s;
    else lostcnt.push_back(i);
  }
  for(ll i = 0; i < lostcnt.size(); i++){
    a[lostcnt[i]] = 0;
  }
  if(lostcnt.size() == 0 && last == 0){
    for(ll i = 0; i < n - 1; i++){
      cout << a[i] << " ";
    }cout << a[n - 1] << endl;
  }else if(lostcnt.size() < 1 && last){
    cout << - 1 << endl;
  }else{
    // Xを越えないようにbitを立てる
    ll pt = 0;
    while(pt < lostcnt.size() && last){
      for(ll i = log2(last + 1); i >= 0; i--){
        if((last >> i) % 2){
          // 1 bit
          if(x - a[lostcnt[pt]] >= (1 << i)){
            a[lostcnt[pt]] += (1 << i);
            last -= (1 << i);
          }else{
            pt++;
            break;
          }
        }
      }
    }
    if(last){
      cout << - 1 << endl;
    }else{
      for(ll i = 0; i < n - 1; i++){
        cout << a[i] << " ";
      }cout << a[n - 1] << endl;
    }
  }
}
