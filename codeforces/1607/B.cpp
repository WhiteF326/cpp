#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define const constexpr
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int t; cin >> t;
  query(t){
    ll x, n; cin >> x >> n;
    // last 4 time is important?
    ll st = (n / 4) * 4 + 1;
    for(ll c = st; c <= n; c++){
      if(x % 2){
        x += c;
      }else{
        x -= c;
      }
    }

    cout << x << endl;
  }
}