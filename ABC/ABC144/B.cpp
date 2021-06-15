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
  vector<bool> p(101, false);
  for(int i = 1; i <= 9; i++){
    for(int j = 1; j <= 9; j++){
      p[i * j] = true;
    }
  }
  cout << (p[n] ? "Yes" : "No") << endl;
}