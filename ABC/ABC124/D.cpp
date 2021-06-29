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
  int n, k; cin >> n >> k;
  string s; cin >> s;
  
  auto rl = runLength(s).encode();
  if(s[0] == '0') rl.insert(rl.begin(), make_pair('1', 0));
  if(s[n - 1] == '0') rl.emplace_back(make_pair('1', 0));

  int ans = 0;
  if(rl.size() < k * 2 + 1){
    cout << n << endl;
  }else{
    for(int i = 0; i <= rl.size() - (k * 2 + 1); i += 2){
      int res = 0;
      for(int j = 0; j < k * 2 + 1; j++){
        if(i + j < rl.size()) res += rl[i + j].second;
        else break;
      }
      ans = max(ans, res);
    }
    cout << ans << endl;
  }
}