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
  string x = "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ";

  for(int i = 0; i < s.length(); i++){
    for(int j = 0; j < 26; j++){
      if(s[i] == x[j]){
        cout << x[j + n];
      }
    }
  }
  cout << endl;
}