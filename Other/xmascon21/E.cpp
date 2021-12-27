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
#define query(t) for(int _ = 0; _ < t; _++)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


#define m_pi 3.141592653589793238462
#define m_e 2.718281828459045
#define eps 0.000000000001

int main(){
  int n = 1000;
  vector<ld> ans;
  ans.push_back(0);
  ans.push_back(2 * m_pi);
  ld current = 2 * m_pi;
  for(int i = 0; i < n; i++){
    ld x = cos(2 * m_pi * m_e * i);
    ld y = sin(2 * m_pi * m_e * i);
    ld d = atan2(y, x);
    if(d < 0) d = 2 * m_pi + d;
    ans.push_back(d);

    sort(all(ans));
    ld mx = 0;
    for(int i = 0; i < ans.size() - 1; i++){
      mx = max(mx, ans[i + 1] - ans[i]);
    }

    // cout << fs(12) << mx << " ";

    if(current - mx > eps){
      cout << i << endl;
    }
    current = mx;
  }
}