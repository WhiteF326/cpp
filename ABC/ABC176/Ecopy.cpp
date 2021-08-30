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

int main(){
  cout << "OK" << endl;
  ifstream ifs("test.txt");
  int h, w, m; ifs >> h >> w >> m;
  vector<pair<int, int>> pos(m);
  
  map<int, int> hl, wl;
  for(int i = 0; i < m; i++){
    int hx, wx; ifs >> hx >> wx;
    hx--, wx--;
    pos[i] = mp(hx, wx);
    hl[hx]++, wl[wx]++;
  }

  set<pair<int, int>> psl;
  for(int i = 0; i < m; i++) psl.insert(pos[i]);

  int hmax = 0, wmax = 0;
  for(auto hx : hl) hmax = max(hmax, hx.second);
  for(auto wx : wl) wmax = max(wmax, wx.second);
  
  vector<int> hkeys, wkeys;
  for(auto hx : hl){
    if(hx.second == hmax) hkeys.emplace_back(hx.first);
  }
  for(auto wx : wl){
    if(wx.second == wmax) wkeys.emplace_back(wx.first);
  }

  cout << "OK" << endl;

  for(int i : hkeys){
    for(int j : wkeys){
      if(psl.find({i, j}) == psl.end()){
        cout << hmax + wmax << endl;
        return 0;
      }
    }
  }

  cout << hmax + wmax - 1 << endl;
}