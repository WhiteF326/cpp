#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(i, j) make_pair(i, j);
using ll = long long;
using ld = long double;

int main(){
  int n, k; cin >> n >> k;
  string s; cin >> s;
  for(int i = 0; i < n; i++){
    if(i == k - 1) cout << (char)(s[i] + 32);
    else cout << s[i];
  }cout << endl;
}