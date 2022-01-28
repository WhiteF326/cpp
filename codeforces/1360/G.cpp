#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


ll gcd(ll x, ll y){
  while(y > 0){
    ll r = x % y;
    x = y;
    y = r;
  }
  return x;
}
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int t; cin >> t;
  query(t){
    int n, m, a, b; cin >> n >> m >> a >> b;
    if(n * a != m * b){
      cout << "NO" << endl;
    }else{
      cout << "YES" << endl;
      int g = gcd(m, a);
      
      string res = "";
      for(int i = 0; i < m / g; i++){
        res += '0';
      }
      for(int i = 0; i < a / g; i++){
        res[i] = '1';
      }

      for(int i = 0; i < n; i++){
        for(int j = 0; j < g; j++){
          cout << res;
        }cout << endl;
        res = res.substr(1) + res[0];
      }
    }
  }
}