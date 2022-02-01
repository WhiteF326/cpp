#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


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
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n, k; cin >> n >> k;
  string s; cin >> s;

  vector<pair<char, int>> r;
  if(s[0] == '0') r.push_back({'1', 0});
  auto rv = runLength(s).encode();
  r.insert(r.end(), all(rv));
  if(s[n - 1] == '0') r.push_back({'1', 0});
 
  int ans = 0;
  if(r.size() < k * 2 + 1){
    cout << n << endl;
  }else{
    for(int i = 0; i <= r.size() - (k * 2 + 1); i += 2){
      int res = 0;
      for(int j = 0; j < k * 2 + 1; j++){
        if(i + j < r.size()) res += r[i + j].second;
        else break;
      }
      ans = max(ans, res);
    }
    cout << ans << endl;
  }
}