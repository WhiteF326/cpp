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
  int n, k; cin >> n >> k;
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
  for(int i = 0; i < n; i++){
    ll a, b; cin >> a >> b;
    q.push(make_pair(a, b));
  }
  ll ans = 0;
  for(int i = 0; i < k; i++){
    auto x = q.top();
    q.pop();

    ans += x.first;
    
    x.first += x.second;
    q.push(x);
  }
  cout << ans << endl;
}
