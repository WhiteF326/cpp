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
  ld n, m, d; cin >> n >> m >> d;
  ld p = 0;
  if(d == 0){
    p = 1 / n;
  }else{
    p = (2 * (n - d)) / (n * n);
  }

  cout << fs(10) << p * (m - 1) << endl;
}