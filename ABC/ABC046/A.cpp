#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  set<int> a;
  for(int i = 0; i < 3; i++){
    int n; cin >> n;
    a.insert(n);
  }
  cout << a.size() << endl;
}