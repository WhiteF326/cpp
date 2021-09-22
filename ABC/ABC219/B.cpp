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
  string s[] = {"", "", ""};
  for(int i = 0; i < 3; i++) cin >> s[i];
  string t; cin >> t;

  for(char x : t){
    cout << s[x - '1'];
  }cout << endl;
}