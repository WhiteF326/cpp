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
  set<string> ans;
  ans.insert("ABC");
  ans.insert("ARC");
  ans.insert("AGC");
  ans.insert("AHC");
  for(int i = 0; i < 3; i++){
    string s; cin >> s;
    ans.erase(s);
  }
  cout << *ans.begin() << endl;
}