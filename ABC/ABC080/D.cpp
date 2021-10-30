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
  int n, c; cin >> n >> c;
  vector<vector<pair<int, int>>> cl(c);
  for(int i = 0; i < n; i++){
    int s, t, cx; cin >> s >> t >> cx;
    cl[cx - 1].push_back(mp(s, t));
  }
  vector<pair<int, int>> ranges(0);
  for(int i = 0; i < c; i++){
    vector<int> im(100001, 0);
    for(auto pl : cl[i]){
      im[pl.first]++, im[pl.second]--;
    }
    queue<int> q;
    for(int i = 0; i <= 100000; i++){
      if(im[i]) q.push(i);
      if(q.size() == 2){
        pair<int, int> px;
        px.first = q.front(); q.pop();
        px.second = q.front(); q.pop();
        ranges.push_back(px);
      }
    }
  }

  vector<int> ims(200001, 0);
  for(auto p : ranges){
    ims[p.first * 2 - 1]++, ims[p.second * 2]--;
  }
  for(int i = 0; i < 200000; i++) ims[i + 1] += ims[i];

  cout << *max_element(all(ims)) << endl;
}