#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  int n; cin >> n;
  vector<pair<string, int>> songs(n);
  for(int i = 0; i < n; i++){
    string s; int x; cin >> s >> x;
    songs[i] = mp(s, x);
  }
  string x; cin >> x;
  bool flg = false;
  int ans = 0;
  for(auto itr = songs.begin(); itr != songs.end(); itr++){
    if(flg) ans += itr->second;
    if(itr->first == x) flg = true;
  }
  cout << ans << endl;
}