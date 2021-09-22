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


int main(){
  int x, y, z; cin >> x >> y >> z;
  vector<int> mx = {x, y, z};
  int k; cin >> k;

  vector<ll> a(x), b(y), c(z);
  for(int i = 0; i < x; i++) cin >> a[i];
  for(int i = 0; i < y; i++) cin >> b[i];
  for(int i = 0; i < z; i++) cin >> c[i];
  
  sort(all(a), greater<ll>());
  sort(all(b), greater<ll>());
  sort(all(c), greater<ll>());

  vector<vector<ll>> cl = {a, b, c};

  map<ll, ll> anslist;

  priority_queue<pair<ll, vector<int>>> q;
  q.push({a[0] + b[0] + c[0], {0, 0, 0}});

  auto hash = [](vector<int> h){
    return (ll)h[0] * 1000000L + (ll)h[1] * 1000L + (ll)h[2];
  };
  while(anslist.size() < k){
    auto p = q.top();
    q.pop();

    anslist[hash(p.second)] = p.first;
    for(int i = 0; i < 3; i++){
      if(p.second[i] + 1 < mx[i]){
        auto np = p.second;
        np[i]++;
        ll cost = cl[0][np[0]] + cl[1][np[1]] + cl[2][np[2]];
        q.push({cost, np});
      }
    }
  }

  priority_queue<ll> ansq;
  for(auto p : anslist) ansq.push(p.second);
  while(!ansq.empty()){
    cout << ansq.top() << endl;
    ansq.pop();
  }
}