#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;

void no(){
  cout << "No" << endl;
  exit(0);
}
void yes(){
  cout << "Yes" << endl;
  exit(0);
}

int main(){
  int n; cin >> n;
  
  auto read = [&](){
    set<pair<int, int>> sr;
    for(int i = 0; i < n; i++){
      string s; cin >> s;
      for(int j = 0; j < n; j++){
        if(s[j] == '#') sr.insert(mp(i, j));
      }
    }
    return sr;
  };

  auto s = read(), t = read();
  if(s.size() != t.size()) no();

  vector<pair<int, int>> sr = vector<pair<int, int>>(all(s));
  vector<pair<int, int>> tr = vector<pair<int, int>>(all(t));

  for(int i = 0; i < 4; i++){
    auto ms = sr[0];
    vector<pair<int, int>> sv(0), tv(0);
    for(auto itr = sr.begin(); itr != sr.end(); itr++){
      sv.emplace_back(mp(itr->first - ms.first, itr->second - ms.second));
    }
    sort(all(sv));
    auto mt = tr[0];
    for(auto itr = tr.begin(); itr != tr.end(); itr++){
      tv.emplace_back(mp(itr->first - mt.first, itr->second - mt.second));
    }
    sort(all(tv));

    bool flg = true;
    for(int i = 0; i < s.size(); i++){
      if(sv[i].first != tv[i].first || sv[i].second != tv[i].second){
        flg = false;
      }
    }

    if(flg) yes();

    // t を転回する
    for(int i = 0; i < t.size(); i++){
      tr[i] = mp(tr[i].second, -tr[i].first);
    }
    sort(all(tr));
  }
  no();
}