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
  map<ll, ll> a;
  for(int i = 0; i < n; i++){
      int x; cin >> x;
      a[x]++;
  }
  vector<pair<ll, ll>> mp;
  for(auto itr = a.begin(); itr != a.end(); itr++){
    if(itr->second >= 2){
      mp.push_back(make_pair(itr->first, itr->second));
    }
  }
  if(mp.size() == 0){
    cout << 0 << endl;
    return 0;
  }else if(mp.size() < 2 && mp[0].second < 4){
    cout << 0 << endl;
    return 0;
  }
  int d = mp.size() - 1;
  sort(mp.begin(), mp.end());
  if(mp[d].second >= 4){
    cout << mp[d].first * mp[d].first << endl;
  }else{
    cout << mp[d].first * mp[d - 1].first << endl;
  }
}