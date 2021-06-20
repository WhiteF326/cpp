#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  int n; cin >> n;
  int diff = 0;
  for(int i = 0; i < n; i++){
    int p; cin >> p;
    if(p != i + 1) diff++;
  }
  if(diff <= 2) cout << "YES" << endl;
  else cout << "NO" << endl;
}