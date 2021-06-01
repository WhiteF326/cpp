#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j);
using ll = long long;
using ld = long double;

int main(){
  int n; cin >> n;
  map<string, pair<bool, bool>> m;
  for(int i = 0; i < n; i++){
    string s; cin >> s;
    string t = s;
    if(t.substr(0, 1) == "!"){
      t.erase(0, 1);
      m[t].second = true;
    }else{
      m[s].first = true;
    }
  }
  for(auto itr = m.begin(); itr != m.end(); itr++){
    if(itr->second.first && itr->second.second){
      cout << itr->first << endl;
      return 0;
    }
  }
  cout << "satisfiable" << endl;
}