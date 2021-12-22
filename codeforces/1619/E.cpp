#include <bits/stdc++.h>
using namespace std;

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
  int t; cin >> t;
  query(t){
    int n;
    scanf("%d", &n);
    vector<ll> v(n);
    aryin(v, n);

    vector<ll> ctr(n + 1);
    for(ll i = 0; i < n; i++) ctr[v[i]]++;

    // smooth
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    vector<ll> dist(n + 1, 0);
    for(ll i = n; i >= 0; i--){
      if(ctr[i] == 0){
        pq.push(i);
      }else if(ctr[i] > 1){
        for(ll j = 0; j < ctr[i] - 1; j++){
          if(pq.empty()) break;
          
          ll dest = pq.top();
          pq.pop();

          dist[dest] = dest - i;
        }
      }
    }

    for(ll i = 1; i <= n; i++) dist[i] += dist[i - 1];

    ll xl;
    if(pq.empty()){
      xl = n + 2;
    }else{
      xl = pq.top() + 1;
    }

    // answer
    cout << ctr[0] << " ";

    for(ll i = 1; i <= n; i++){
      if(xl <= i){
        cout << -1 << " ";
      }else{
        cout << ctr[i] + dist[i - 1] << " ";
      }
    }
    cout << endl;
  }
}