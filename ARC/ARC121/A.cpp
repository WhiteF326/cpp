// this problem sucks I'll never do this again

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j);
using ll = long long;
using ld = long double;

const ll modv = 1000000007;

int main(){
  int n; cin >> n;
  vector<pair<ll, ll>> pt(n);
  for(int i = 0; i < n; i++){
    ll x, y; cin >> x >> y;
    pt[i] = mp(x, y);
  }
  sort(pt.begin(), pt.end());
  vector<pair<ll, ll>> anslist(0);
  anslist.emplace_back(pt[0]);
  anslist.emplace_back(pt[1]);
  anslist.emplace_back(pt[n - 1]);
  if(n > 3) anslist.emplace_back(pt[n - 2]);
  for(int i = 0; i < n; i++){
    pt[i] = mp(-pt[i].second, pt[i].first);
  }
  sort(pt.begin(), pt.end());
  anslist.emplace_back(make_pair(pt[0].second, -pt[0].first));
  anslist.emplace_back(make_pair(pt[1].second, -pt[1].first));
  anslist.emplace_back(make_pair(pt[n - 1].second, -pt[n - 1].first));
  if(n > 3) anslist.emplace_back(make_pair(pt[n - 2].second, -pt[n - 2].first));
  vector<ll> res(64, 0);
  for(int i = 0; i < anslist.size() -1; i++){
    for(int j = i + 1; j < anslist.size(); j++){
      res[i * 8 + j] = max(anslist[i].first - anslist[j].first, anslist[i].second - anslist[j].second);
    }
  }
  sort(res.begin(), res.end(), greater<ll>());
  cout << res[1] << endl;
}
