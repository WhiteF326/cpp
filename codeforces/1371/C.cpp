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


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int t; cin >> t;
  query(t){
    ll a, b, n, m; cin >> a >> b >> n >> m;
    
    if(n + m > a + b){
      cout << "No" << endl;
      continue;
    }

    bool ans = false;
    
    ll v = min(abs(a - b), n);

    n -= v;
    if(a < b) b -= v;
    else a -= v;

    if(a != b){
      if(min(a, b) >= m) ans = true;
    }else{
      if(m <= a && n <= a + b - m) ans = true;
    }

    cout << (ans ? "Yes" : "No") << endl;
  }
}