#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

struct runLength{
  string s;
  
  runLength(string s){
    this->s = s;
  }

  vector<pair<char, int>> encode() {
    int n = (int)this->s.size();
    vector<pair<char, int>> ret;
    for (int l = 0; l < n;) {
      int r = l + 1;
      for (; r < n && this->s[l] == this->s[r]; r++) {};
      ret.push_back({this->s[l], r - l});
      l = r;
    }
    return ret;
  }

  string decode(const vector<pair<char, int>>& code) {
    string ret = "";
    for (auto p : code) {
      for (int i = 0; i < p.second; i++) {
        ret.push_back(p.first);
      }
    }
    return ret;
  }
};

int main(){
  int n; cin >> n;
  string s; cin >> s;
  
  int bc = 0, wc = count(s.begin(), s.end(), '.');
  int ans = wc;
  
  for(int i = 0; i < n; i++){
    if(s[i] == '.'){
      wc--;
    }else{
      bc++;
    }
    ans = min(ans, bc + wc);
  }

  cout << ans << endl;
}