#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  int h, n; cin >> h >> n;
  int res = 0;
  for(int i = 0; i < n; i++){
    int a; cin >> a;
    res += a;
  }
  cout << (res >= h ? "Yes" : "No") << endl;
}