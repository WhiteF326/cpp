#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  int k; cin >> k;
  string s; cin >> s;
  if(k >= s.length()){
    cout << s << endl;
  }else{
    cout << s.substr(0, k) << "..." << endl;
  }
}