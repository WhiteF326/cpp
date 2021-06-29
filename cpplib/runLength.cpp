#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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