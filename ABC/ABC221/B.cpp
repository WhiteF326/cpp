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
  string s, t; cin >> s >> t;
  if(s == t) cout << "Yes" << endl;
  else{
    for(int i = 0; i < s.length() - 1; i++){
      swap(s[i], s[i + 1]);
      if(s == t){
        cout << "Yes" << endl;
        return 0;
      }
      swap(s[i], s[i + 1]);
    }
    cout << "No" << endl;
  }
}