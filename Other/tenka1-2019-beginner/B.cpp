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
  string s; cin >> s;
  int k; cin >> k; k--;
  for(int i = 0; i < n; i++){
    if(s[i] != s[k]) cout << "*";
    else cout << s[i];
  }cout << endl;
}