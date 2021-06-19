#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(i, j) make_pair(i, j);
using ll = long long;
using ld = long double;

int main(){
  int n; cin >> n;
  string s; cin >> s;
  if(n % 2) cout << "No" << endl;
  else{
    bool flg = true;
    for(int i = 0; i < n / 2; i++){
      if(s[i] != s[i + n / 2]) flg = false;
    }
    cout << (flg ? "Yes" : "No") << endl;
  }
}