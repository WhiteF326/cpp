#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


struct Edge{
  int left;
  int right;
  ll weight;
};
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int t; cin >> t;
  query(t){
    int n, m; cin >> n >> m;

    vector<vector<Edge>> e(m);
    for(int i = 0; i < m; i++){
      int a, b; ll w; cin >> a >> b >> w;
      e[a - 1].push_back({a - 1, b - 1, w});
      e[b - 1].push_back({b - 1, a - 1, w});
    }

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
    q.push({0, 0});
    vector<ll> w(n, LLONG_MAX);
    w[0] = 0;

    while(!q.empty()){
      auto dest = q.top();
      q.pop();

      for(auto v : e[dest.second]){
        int next = v.right;
        ll wg = dest.first | v.weight;
        if(w[next] > wg){
          w[next] = wg;
          q.push({wg, next});
        }
      }
    }

    cout << *max_element(all(w)) << endl;
  }
}