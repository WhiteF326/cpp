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
  int n, z, w; cin >> n >> z >> w;
  vector<int> a(n); aryin(a, n);

  if(n == 1){
    cout << abs(a[0] - w) << endl;
  }else{
    cout << max(abs(a[n - 1] - w), abs(a[n - 2] - a[n - 1])) << endl;
  }
}