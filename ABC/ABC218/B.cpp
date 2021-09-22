#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;

int main(){
  for(int i = 0; i < 26; i++){
    int p; cin >> p;
    cout << (char)('a' + p - 1);
  }
  cout << endl;
}