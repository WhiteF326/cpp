#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define const constexpr
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;
#define query(t) for(int _ = 0; _ < t; _++)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


int main(){
  int n, m; cin >> n >> m;
  // 2, 3, 4
  if(n * 2 > m || n * 4 < m){
    cout << "-1 -1 -1" << endl;
  }else{
    int a, b, c;
    b = m % 2;
    n -= b, m -= b * 3;
    c = (m - 2 * n) / 2;
    a = (m - 4 * c) / 2;

    cout << a << " " << b << " " << c << endl;
  }
}