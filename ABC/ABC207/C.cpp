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
  vector<pair<int, pair<ll, ll>>> p(n, pair<int, pair<ll, ll>>());

  for(int i = 0; i < n; i++){
    cin >> p[i].first;
    cin >> p[i].second.first >> p[i].second.second;
    p[i].second.first *= 10, p[i].second.second *= 10;
    switch(p[i].first){
      case 1:
        break;
      
      case 2:
        p[i].second.second--;
        break;

      case 3:
        p[i].second.first++;
        break;
      
      case 4:
        p[i].second.first++, p[i].second.second--;
        break;
    }
  }

  int ans = 0;
  for(int i = 0; i < n - 1; i++){
    for(int j = i + 1; j < n; j++){
      bool flg = false;
      if(p[i].second.first <= p[j].second.first && p[j].second.first <= p[i].second.second) flg = true;
      if(p[j].second.first <= p[i].second.first && p[i].second.first <= p[j].second.second) flg = true;
      ans += flg;
    }
  }
  cout << ans << endl;
}