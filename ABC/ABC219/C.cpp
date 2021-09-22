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
  string x; cin >> x;
  int n; cin >> n;

  auto encode = [&](string s){
    string ret = s;
    for(char &c : ret){
      c = (char)('a' + (x.find(c)));
    };
    return ret;
  };
  auto decode = [&](string s){
    string ret = s;
    for(char &c : ret){
      c = x[c - 'a'];
    }
    return ret;
  };

  vector<string> s(n);
  for(int i = 0; i < n; i++) cin >> s[i];
  for(int i = 0; i < n; i++) s[i] = encode(s[i]);
  sort(all(s));
  for(int i = 0; i < n; i++) cout << decode(s[i]) << endl;
}