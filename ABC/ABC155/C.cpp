#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;
  unordered_map<string, int> s;
  for(int i = 0; i < n; i++){
    string key; cin >> key;
    auto itr = s.find(key);
    if(itr != s.end()){
      s[key]++;
    }else{
      s[key] = 0;
    }
  }
  int mx = 0;
  for(auto itr = s.begin(); itr != s.end(); itr++){
    mx = max(mx, itr->second);
  }
  vector<string> ans(0);
  for(auto itr = s.begin(); itr != s.end(); itr++){
    if(itr->second == mx){ans.push_back(itr->first);}
  }
  sort(ans.begin(), ans.end());
  for(int i = 0; i < ans.size(); i++){
    cout << ans[i] << endl;
  }
}