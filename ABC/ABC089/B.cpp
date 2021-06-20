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
  bool yf = false;
  for(int i = 0; i < n; i++){
    string s; cin >> s;
    if(s == "Y") yf = true;
  }
  cout << (yf ? "Four" : "Three") << endl;
}