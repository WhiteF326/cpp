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
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  unordered_map<string, int> st;
  int n; cin >> n;
  for(int i = 0; i < n; i++){
    string s; cin >> s;
    st[s]++;
  }
  int c = 0;
  for(auto p : st){
    if(c < p.second) c = p.second;
  }

  vector<string> keys;
  for(auto p : st){
    keys.emplace_back(p.first);
  }
  sort(all(keys));
  for(string s : keys){
    if(c == st[s]) cout << s << endl;
  }
}