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
    int a, b; cin >> a >> b;
    int ans = 0;
    if(a < b) swap(a, b);
    
    // make 3, 1
    int c = min(min(a / 3, b), (a - b) / 2);
    a -= c * 3, b -= c;
    ans += c;
    int d = min(a, b) / 2;
    ans += d;

    cout << ans << endl;
  }
}