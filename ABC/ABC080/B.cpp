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
  string x = to_string(n);
  int f = 0;
  for(int i = 0; i < x.length(); i++){
    f += stoi(x.substr(i, 1));
  }
  cout << (n % f ? "No" : "Yes") << endl;
}