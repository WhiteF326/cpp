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
  int h, w; cin >> h >> w;
  int n; cin >> n;
  set<int> al, bl;
  vector<pair<int, int>> ab(n);
  for(int i = 0; i < n; i++){
    int a, b; cin >> a >> b;
    ab[i] = mp(a, b);
    al.insert(a);
    bl.insert(b);
  }
  vector<int> alist(0), blist(0);
  for(auto itr = al.begin(); itr != al.end(); itr++){
    alist.push_back(*itr);
  }
  for(auto itr = bl.begin(); itr != bl.end(); itr++){
    blist.push_back(*itr);
  }
  
  vector<pair<int, int>> anslist(n);
  for(int i = 0; i < n; i++){
    anslist[i].first = lower_bound(all(alist), ab[i].first) - alist.begin();
    anslist[i].second = lower_bound(all(blist), ab[i].second) - blist.begin();
  }
  for(int i = 0; i < n; i++){
    cout << anslist[i].first + 1 << " " << anslist[i].second + 1 << endl;
  }
}