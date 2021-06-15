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
  bool ans = true;
  for(int i = 0; i < n; i++){
    int a; cin >> a;
    if(a % 3 && a % 5 && !(a % 2)) ans = false;
  }
  cout << (ans ? "APPROVED" : "DENIED") << endl;
}