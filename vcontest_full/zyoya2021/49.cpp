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
  double a, b, x; cin >> a >> b >> x;

  cout << fs(12);

  if(a * a * b / 2.0 <= x){
    cout << 180.0 * atan(2.0 * (a * a * b - x) / (a * a * a)) / acos(-1) << endl;
  }else{
    cout << 180.0 * atan(a * b * b / 2.0 / x) / acos(-1) << endl;
  }
}