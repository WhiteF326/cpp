#include <bits/stdc++.h>
using namespace std;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define const constexpr
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;

int main(){
  int t; cin >> t;
  // diff 0, 1, 2?
  for(int i = 0; i < t; i++){
    int a, b; cin >> a >> b;
    if(a == 0 && b == 0) cout << 0 << endl;
    else if(a == b) cout << 1 << endl;
    else if(abs(a - b) % 2 == 1) cout << -1 << endl;
    else cout << 2 << endl;
  }
}