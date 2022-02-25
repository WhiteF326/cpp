#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  ll a, b; cin >> a >> b;
  ll ans = 0;
  while(a % 4 != 0){
    ans ^= a;
    a++;
  }
  a += ((b - a) / 4) * 4;
  while(a <= b){
    ans ^= a;
    a++;
  }
  cout << ans << endl;
}