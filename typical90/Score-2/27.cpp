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
  map<string, bool> res;
  for(int i = 0; i < n; i++){
    string s; cin >> s;
    if(!res[s]){
      res[s] = true;
      cout << i + 1 << endl;
    }
  }
}