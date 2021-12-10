#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define const constexpr
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;
#define query(t) for(int _ = 0; _ < t; _++)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


int main(){
  int h, w; cin >> h >> w;
  vector<vector<int>> hlist(w), wlist(h);
  map<int, bool> x;

  for(int i = 0; i < w; i++) hlist[i].push_back(-1);

  for(int i = 0; i < h; i++){
    wlist[i].push_back(-1);
    string s; cin >> s;
    for(int j = 0; j < w; j++){
      if(s[j] == '#'){
        hlist[j].push_back(i);
        wlist[i].push_back(j);
        x[i * w + j] = true;
      }
    }
    wlist[i].push_back(w);
  }

  for(int i = 0; i < w; i++) hlist[i].push_back(h);

  for(int i = 0; i < w; i++) sort(all(hlist[i]));
  for(int i = 0; i < h; i++) sort(all(wlist[i]));

  int ans = 0;
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      if(x[i * w + j]) continue;
      // vertical
      auto hitr = upper_bound(all(hlist[j]), i);
      int down = *hitr;
      hitr--;
      int up = *hitr;
      // horizontal
      auto vitr = upper_bound(all(wlist[i]), j);
      int right = *vitr;
      vitr--;
      int left = *vitr;
      // mix
      // cout << up << " " << down << " " << left << " " << right << endl;
      int res = (down - up - 1) + (right - left - 1) - 1;
      ans = max(ans, res);
    }
  }

  cout << ans << endl;
}