#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  int n, s, d; cin >> n >> s >> d;
  bool ans = false;
  for(int i = 0; i < n; i++){
    int x, y; cin >> x >> y;
    if(x < s && y > d) ans = true;
  }
  cout << (ans ? "Yes" : "No") << endl;
}