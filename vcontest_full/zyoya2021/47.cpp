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
  
  string s; cin >> s;
  auto p = runLength(s).encode();

  cout << p.size() - 1 << endl;
}