#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  int n; cin >> n;
  map<int, int> sp;
  for(int i = 0; i < n; i++){
    int x; cin >> x;
    sp[x]++;
  }
  cout << sp.size() - !(sp.size() % 2) << endl;
}