#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  string s; cin >> s;
  if(s.length() == 2){
    cout << s << endl;
  }else{
    reverse(s.begin(), s.end());
    cout << s << endl;
  }
}